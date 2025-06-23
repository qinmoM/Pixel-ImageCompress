/*              Pixel-ImageCompression
 *  The number of the mapping arrary elements should not be too large
 *  otherwise it will cause performance issues.
 *  About 20000 pixels sqares cen be drawn in 1 millisecond.
 * */

#include <iostream>
#include <raylib.h>
#include <ctime>
#include "PixelMappingTable.h"

const int WIDTH = 40;                           // the number of pixels in width after compression
const int HEIGHT = 79;                          // the number of pixels in height after compression
const char* IMAGE = "res/Pixel_fufu.png";       // the path of the image file

const int SIZE = 10;                            // the size of each pixel in the preview window
const Color COLOR = { 200, 200, 200, 255 };     // tht color of the background when previewing

int main()
{
    Image image = LoadImage(IMAGE); // load image
    PixelMappingTable table; // initialize mapping table
    std::vector<std::vector<Color>> array = table.getOriginalColor(image, WIDTH, HEIGHT); // original color
    std::vector<std::vector<uint8_t>> mapping; // finial mapping array
    mapping = table.getMappingArray(array); // get mapping array

    std::cout << "{\n";
    for (int i = 0; i < mapping.size(); i++)
    {
        std::cout << "{";
        for (int j = 0; j < mapping[i].size(); j++)
        {
            std::cout << static_cast<int>(mapping[i][j]);
            if (mapping[i].size() - 1 != j)
            {
                std::cout << ", ";
            }
        }
        if (mapping.size() - 1 == i)
        {
            std::cout << "}\n";
        }
        else
        {
            std::cout << "},\n";
        }
    }
    std::cout << "}\n";

    InitWindow(WIDTH * SIZE, HEIGHT * SIZE, "Preview"); // initialize window

    SetTargetFPS(60); // set FPS
    while (!WindowShouldClose()) // main loop
    {
        BeginDrawing(); // begin drawing
        ClearBackground(COLOR); // clear background

        // std::cout << clock() << " ";
        for (int i = 0; i < mapping.size(); i++)
        {
            for (int j = 0; j < mapping[i].size(); j++)
            {
                DrawRectangle(j * SIZE, i * SIZE, SIZE, SIZE, table.colorPalette[mapping[i][j]]);
            }
        }
        // std::cout << clock() << "\n";

        EndDrawing(); // end drawing
    }

    CloseWindow(); // close window
    return 0;
}