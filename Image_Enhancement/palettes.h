#pragma once
#include <vector>
#include <cmath>
void linear_palette(int min,int max, std::vector<int> &palette, int slope);
void inv_linear_palette(int min,int max, std::vector<int> &palette );
void gamma_correction_palette(int min,int max, std::vector<int> &palette,float gamma, float slope);

struct Interval_Slope{
    const int l_B;
    const int u_B;
    const float change_ratio;
    constexpr Interval_Slope(const int _upperBound,const int _lowerBound, const float _slope)
    :                        u_B(_upperBound),l_B(_lowerBound),change_ratio(_slope){}
};

enum Mode:unsigned int{
    PALETTE_ZERO_OUTBOUNDS,
    PALETTE_MIN_OUTBOUNDS,
    PALETTE_ADAPT_LEFT,
    PALETTE_ADAPT_RIGH,
    PALETTE_IGNORE_OUTBOUNDS
};
void sawtooth_palette(int min,int max, std::vector<int> &palette , std::vector<Interval_Slope> &intervals,Mode outer_bounds_mode );