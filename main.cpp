#include <iostream>
#include <raylib.h>
#include <ctime>
#include "PixelMappingTable.h"

// The number of the mapping arrary elements should not be too large
// otherwise it will cause performance issues.
// About 20000 pixels sqares cen be drawn in 1 millisecond.

int main()
{
    Image image = LoadImage("res/Pixel_piao.jpg"); // load image
    PixelMappingTable table; // initialize mapping table
    std::vector<std::vector<Color>> array = table.getOriginalColor(image, 37, 52); // original color
    std::vector<std::vector<uint8_t>> mapping; // finial mapping array
    mapping = table.getMappingArray(array); // get mapping array

    std::cout << "{ ";
    for (int i = 0; i < mapping.size(); i++)
    {
        std::cout << "{";
        for (int j = 0; j < mapping[i].size(); j++)
        {
            std::cout << static_cast<int>(mapping[i][j]) << ", ";
        }
        std::cout << "},\n";
    }
    std::cout << "}\n";

    InitWindow(849, 1200, "Pixel Color Mapping Table"); // initialize window
    int size = 4;
    SetTargetFPS(60); // set FPS
    while (!WindowShouldClose()) // main loop
    {
        BeginDrawing(); // begin drawing
        ClearBackground(WHITE); // clear background

        // std::cout << clock() << " ";
        for (int i = 0; i < mapping.size(); i++)
        {
            for (int j = 0; j < mapping[i].size(); j++)
            {
                DrawRectangle(j * size, i * size, size, size, table.colorPalette[mapping[i][j]]);
            }
        }
        // std::cout << clock() << "\n";

        EndDrawing(); // end drawing
    }

    CloseWindow(); // close window
    return 0;
}