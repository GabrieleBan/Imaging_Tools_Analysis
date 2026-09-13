#include <palettes.h>

void linear_palette(int min,int max, std::vector<int> &palette, int slope=1){
    palette.clear();
    if (min<0)
        min=0;
    for(int i=0;i<min;i++){
        palette.push_back(0);
    }
    for(int i =min;i<=max;i++){
        palette.push_back(i);
    }
}

void sawtooth_palette(int min,int max, std::vector<int> &palette , std::vector<Interval_Slope> &intervals,SawMode outer_bounds_mode ){
    int last_changed=0;
    
    
    for(Interval_Slope range : intervals){
        int i=0;
        
        int low=range.l_B;
        int up=range.u_B;
        int m=range.change_ratio;

        if(low>up){
            low=up;
            up=range.l_B;
            m=-m;
        }
        m=m*((max-low)/(up-low));


        palette.reserve(up);
        for(i=low;i<=up;i++)
        {
            palette.at(i)=m*i-low;
        }
        

        int fill_value;
        switch (outer_bounds_mode)
        {
        case SawMode::ADAPT_LEFT:
            fill_value=low;
            break;
        case SawMode::ADAPT_RIGHT:
            fill_value=up;
            break;
        case SawMode::MIN_OUTBOUNDS:
            fill_value=min;
            break;
        case SawMode::IGNORE_OUTBOUNDS:
            continue;
        default:
            continue;
        }

        for(int j=low;j>last_changed;j--)
        {
            palette.at(j)=fill_value;
        }
        last_changed=i;

    }
    
}

void inv_linear_palette(int min,int max, std::vector<int> &palette ){
    palette.clear();
    for(int i = max;i>=min;i--){
        palette.push_back(i);
        // std::cout<<"palette"<< i <<"/n";
    }
    
}

class ExpFunctor{
    private:
    const float max;
    const float gamma;
    const float slope;

    public:
    ExpFunctor(float _max,float _gamma,float _slope):max(_max),gamma(_gamma),slope(_slope){}
    
    int operator()(int num){
        return int((this->slope)*std::pow(num/max,this->gamma)*max);
    }
    

};

void gamma_correction_palette(int min,int max, std::vector<int> &palette,float gamma, float slope){
    palette.clear();
    ExpFunctor gammaCorrection= ExpFunctor{255.0f,gamma,slope};
    int value;
    for(int i =min;i<=max;i++){
        value=gammaCorrection(i);
        palette.push_back(value);
        // std::cout<<value<<"\n";
    }
    
}