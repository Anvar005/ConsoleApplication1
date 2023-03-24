#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

void write_bmp(const char* filename, unsigned char* img, int w, int h) {
	int filesize = 54 + 3 * w * h;
	unsigned char bmpfileheader[14] = { 'B', 'M', 0,0,0,0, 0,0, 0,0, 54, 0,0,0 };
	unsigned char bmpinfoheader[40] = { 40, 0, 0, 0, 0,0,0,0, 0,0,0,0, 1,0, 24,0 };
	unsigned char bmppad[3] = { 0,0,0 };
	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);

	bmpinfoheader[4] = (unsigned char)(w);
	bmpinfoheader[5] = (unsigned char)(w >> 8);
	bmpinfoheader[6] = (unsigned char)(w >> 16);
	bmpinfoheader[7] = (unsigned char)(w >> 24);
	bmpinfoheader[8] = (unsigned char)(h);
	bmpinfoheader[9] = (unsigned char)(h >> 8);
	bmpinfoheader[10] = (unsigned char)(h >> 16);
	bmpinfoheader[11] = (unsigned char)(h >> 24);
	FILE* file = fopen(filename, "wb");
	fwrite(bmpfileheader, 1, 14, file);
	fwrite(bmpinfoheader, 1, 40, file);
	for (int i = 0; i < h; i++) {
		fwrite(img + (w * (h - i - 1) * 3), 3, w, file);
		fwrite(bmppad, 1, (4 - (w * 3) % 4) % 4, file);
	}

	fclose(file);
}

unsigned char* canvas = nullptr;
int canvas_width;
int canvas_height;

void create_canvas(int width, int height) {
	if (canvas)
		delete[] canvas;
	canvas = new unsigned char[width * height * 3];
	canvas_width = width;
	canvas_height = height;
}

void save(const char* filename) {
	write_bmp(filename, canvas, canvas_width, canvas_height);
}


void set_pixel(int x, int y,
	int r, int g, int b)
{
	if (x < 0 || y < 0 ||
		x >= canvas_width ||
		y >= canvas_height)
	{
		return;
	}
	int i = ((y * canvas_width) + x) * 3;
	canvas[i] = b;
	canvas[i + 1] = g;
	canvas[i + 2] = r;
}

int sum(int argc, ...)
{
	va_list va;
	va_start(va, argc);

	int s = 0;
	for (int i = 0; i < argc; i++)
	{
		s += va_arg(va, int);
	}
	va_end(va, argc);
	return s;
}

int main()
{
	cout << sum(3, 5, 3, 2) << endl;
	return 0;
}
