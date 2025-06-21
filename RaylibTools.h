#ifndef __RAYLIBTOOLS_HPP__
#define __RAYLIBTOOLS_HPP__

#include <raylib.h>
#include <cmath>

class RaylibTools
{
public:
	// Circle line color
	static Color colorCircleLine;
	// Line color
	static Color colorLine;
	// Line size
	static int sizeLine;
	// Line length
	static int lengthLine;
public:
	// Set default color// color: default color
	static void SetColor(Color color);

	// Draw line with color and size// startX, startY: Start point x,y endX, endY: End point x,y color: Line color
	static void DrawLine(int startX, int startY, int endX, int endY, int size, Color color);
	// Draw line with last color// startX, startY: Start point x,y endX, endY: End point x,y size: Line size
	static void DrawLine(int startX, int startY, int endX, int endY, int size);
	// Draw line with last color and size// startX, startY: Start point x,y endX, endY: End point x,y
	static void DrawLine(int startX, int startY, int endX, int endY);
	// Draw line with angle and color// startX, startY: Start point x,y angle: Angle in degrees length: Line length size: Line size color: Line color
	static void DrawLineAngle(int startX, int startY, float angle, int length, int size, Color color);
	// Draw line with angle and last color// startX, startY: Start point x,y angle: Angle in degrees length: Line length size: Line size
	static void DrawLineAngle(int startX, int startY, float angle, int length, int size);
	// Draw line with angle, length and last color and size// startX, startY: Start point x,y angle: Angle in degrees length: Line length
	static void DrawLineAngle(int startX, int startY, float angle);

	// Draw circle line with color// centerX, centerY: Circle center x,y radius: Circle radius size: Line size color: Line color
	static void DrawCircleLine(int centerX, int centerY, float radius, int size, Color color);
	// Draw circle line with last color// centerX, centerY: Circle center x,y radius: Circle radius size: Line size
	static void DrawCircleLine(int centerX, int centerY, float radius, int size);

	// Draw texture with percent size// texture: Image texture x, y: Image position percent: Image size
	static void DrawTexture(Texture2D texture, float x, float y, float percent);
};

#endif // __RAYLIBTOOLS_HPP__