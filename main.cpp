#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>
#include "palettes.h"
// #include <../image_enhancement/palettes.h>

cv::Mat apply_palette(cv::Mat &img,std::vector<int> &palette){
    
    for(int i= 0;i<img.cols;i++){
        for(int j= 0;j<img.rows;j++){
            img.at<uchar>(i, j)=palette.at(img.at<uchar>(i, j));
        }
    }

    return img;
}

int main()
{
    std::cout << "cv version : "<< CV_VERSION << '\n';
    if(std::filesystem::exists("../InImage.png"))
    {
        cv::Mat img= cv::imread(std::filesystem::absolute("../InImage.png").string(),cv::IMREAD_GRAYSCALE);
        if(img.empty()){
            std::cout<<"image empty \n";
            return 0;
        }
        else{
                std::cout<<"found";
        }


        cv::imshow("Original Image",img);
        std::vector<int> palette=std::vector<int>();
        palette.reserve(256);
        // linear_palette(0,255,palette);
        // inv_linear_palette(0,255,palette);
        gamma_correction_palette(0,255,palette,3.0f,1.0f);

        cv::Mat newimg=apply_palette(img,palette);


        cv::imshow("Modified Image",newimg);
    
        cv::waitKey(0);
        cv::destroyAllWindows();

        cv::imwrite(std::filesystem::absolute("../").string()+"/OutImage.png",newimg);

    }
    return 0;
}

