#pragma once
#include <vector>
#include <cmath>
void linear_palette(int min,int max, std::vector<int> &palette, int slope);
void inv_linear_palette(int min,int max, std::vector<int> &palette );
void gamma_correction_palette(int min,int max, std::vector<int> &palette,float gamma, float slope);