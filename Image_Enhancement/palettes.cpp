#include <palettes.h>

void linear_palette(int min,int max, std::vector<int> &palette, int slope=1){
    palette.clear();
    for(int i =min;i<=max;i++){
        palette.push_back(i);
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