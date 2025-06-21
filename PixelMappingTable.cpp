#include "PixelMappingTable.h"

PixelMappingTable::PixelMappingTable()
{
    initColorPalette();
}

void PixelMappingTable::initColorPalette()
{
    int index = 0;

    // opaques
    for (int r = 0; r < 5; r += 1)
    {
        for (int g = 0; g < 5; g += 1)
        {
            for (int b = 0; b < 5; b += 1)
            {
                colorPalette.push_back(Color {
                    static_cast<unsigned char>(r * 64 > 255 ? 255 : r * 64),
                    static_cast<unsigned char>(g * 64 > 255 ? 255 : g * 64),
                    static_cast<unsigned char>(b * 64 > 255 ? 255 : b * 64),
                    255
                });
                index++;
            }
        }
    }

    // transparents
    for (int r = 0; r < 5; r += 1)
    {
        for (int g = 0; g < 5; g += 1)
        {
            for (int b = 0; b < 5; b += 1)
            {
                colorPalette.push_back(Color{
                    static_cast<unsigned char>(r * 64 > 255 ? 255 : r * 64),
                    static_cast<unsigned char>(g * 64 > 255 ? 255 : g * 64),
                    static_cast<unsigned char>(b * 64 > 255 ? 255 : b * 64),
                    128
                });
                index++;
            }
        }
    }

    // default colors
    colorPalette.push_back(Color{0, 0, 0, 0});         // 完全透明
    colorPalette.push_back(Color{255, 0, 0, 255});     // 撞击红
    colorPalette.push_back(Color{0, 255, 255, 255});   // 青
    colorPalette.push_back(Color{255, 0, 255, 255});   // 紫
    colorPalette.push_back(Color{0, 255, 0, 255});     // 绿
    colorPalette.push_back(Color{255, 255, 0, 255});   // 黄
}


std::vector<std::vector<Color>> PixelMappingTable::getOriginalColor(Image image, int x, int y)
{
    int width = image.width;
    int height = image.height;
    int wOffset = width / x / 2;
    int hOffset = height / y / 2;
    std::vector<std::vector<Color>> result;
    Color* data = LoadImageColors(image);
    for (int i = 0; i < y; i++)
    {
        std::vector<Color> temp;
        for (int j = 0; j < x; j++)
        {
            int index = (i * height / y + hOffset) * width + (j * width / x + wOffset);
            temp.push_back(data[index]);
        }
        result.push_back(temp);
    }
    UnloadImageColors(data);
    return result;
}

uint8_t PixelMappingTable::getMapping(Color color)
{
    uint8_t r = color.r;
    uint8_t g = color.g;
    uint8_t b = color.b;
    uint8_t a = color.a;
    uint8_t temp = 0;
    if (64 > a)
    {
        return 250; // transparent
    }
    bool isCarry = false;
    temp = r / 64;
    isCarry = ( (r % 64 > 32) ? true : false);
    r = (isCarry ? temp + 1 : temp);
    temp = g / 64;
    isCarry = ( (g % 64 > 32) ? true : false);
    g = (isCarry ? temp + 1 : temp);
    temp = b / 64;
    isCarry = ( (b % 64 > 32) ? true : false);
    b = (isCarry ? temp + 1 : temp);
    a = (a > 192 ? 0 : 1);
    temp = a * 125 + r * 25 + g * 5 + b;
    return temp;
}

std::vector<std::vector<uint8_t>> PixelMappingTable::getMappingArray(std::vector<std::vector<Color>> array)
{
    if (array.empty())
    {
        return { };
    }
    int width = array[0].size();
    int height = array.size();
    std::vector<std::vector<uint8_t>> result;
    std::vector<uint8_t> temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp.push_back(getMapping(array[i][j]));
        }
        result.push_back(temp);
        temp.clear();
    }
    return result;
}