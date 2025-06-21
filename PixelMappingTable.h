#pragma once

#include <cstdint>
#include <vector>
#include <raylib.h>
#include "RaylibTools.h"

class PixelMappingTable
{
public:
    std::vector<Color> colorPalette;
public:
    PixelMappingTable();
    void initColorPalette();
    std::vector<std::vector<Color>> getOriginalColor(Image image, int x, int y);
    uint8_t getMapping(Color color);
    std::vector<std::vector<uint8_t>> getMappingArray(std::vector<std::vector<Color>> array);
};