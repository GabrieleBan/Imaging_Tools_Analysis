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

enum SawMode:unsigned int{
    ZERO_OUTBOUNDS,
    MIN_OUTBOUNDS,
    ADAPT_LEFT,
    ADAPT_RIGHT,
    IGNORE_OUTBOUNDS
};
void sawtooth_palette(int min,int max, std::vector<int> &palette , std::vector<Interval_Slope> &intervals,SawMode outer_bounds_mode );

void cut_palette(int min , int max, std::vector<int> &palette,std::vector<Interval_Slope> &intervals);