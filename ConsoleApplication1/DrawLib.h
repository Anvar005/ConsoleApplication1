#pragma once
#include <iostream>
#include <sstream>
using namespace std;
const int max_width = 100; // ширина
const int max_height = 60; // высота
int s_width = 50;
int s_height = 30;
char table[max_width][max_height];
void set_size(int width, int height) {
	s_width = width;
	s_height = height;
}
void clear_table() {
	for (int y = 0; y < s_height; y++) {
		for (int x = 0; x < s_width; x++) {
			table[y][x] = ' ';
		}
	}
}
void print_table() {
	system("cls");
	stringstream ss;
	for (int y = 0; y < s_height; y++) {
		for (int x = 0; x < s_width; x++) {
			ss << table[y][x] << " ";
		}
		ss << endl;
	}
	cout << ss.str() << endl << flush;
}
void draw_circle(int r, int cx, int cy, char chr) {
	for (int y = 0; y < s_height; y++) {
		for (int x = 0; x < s_width; x++) {
			int lx = x - cx;
			int ly = y - cy;
			if ((lx * lx + ly * ly) <= r * r) {
				table[y][x] = chr;
			}
		}
	}
}
void draw_rect(int start_x, int start_y, int width, int height, char chr) {
	for (int x = start_x; x < start_x + width && x < s_width; x++) {
		for (int y = start_y; y < start_y + height && y < s_height; y++) {
			table[y][x] = chr;
		}
	}
}

void draw_text(int x, int y, char text[])
{
	for (int i = 0; text[i] != 0 && x + i < s_width; i++) {
		table[y][x + i] = text[i];
	}
}
