#include <iostream>    /*For IO*/
#include <cstdint>     /*For standard variable types*/
#include <random>      /*For random number generation*/
#include <opencv2/opencv.hpp> /*For opencv*/
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cstdio> /*For printf()*/
#include <cstdlib>/*for malloc()*/
//#include "kernel.hpp"

#define RESIZE_TO_DEBUG 1

using namespace std;
using namespace cv;

/*Function Prototypes*/
void flattenImage(cv::Mat image,uint8_t *&img_vec);
void printImageContents(Mat image);


void flattenImage(cv::Mat image,std::vector<uint8_t> &img_vec)
{
  //cout<<"\nIn flattenImage";
  uint16_t m=0,n=0;
  uint32_t total=0;
  m=(uint16_t)image.rows;
  n=(uint16_t)image.cols;
  total=m*n;
  image=image.reshape(1,1);
  for(int i=0;i<total*3;++i)
  {
    img_vec[i]=image.at<uint8_t>(i);
  }
}

void printImageContents(Mat image)
{
  //cout<<"\nIn printImageContents";
  cout<<"\nImage Matrix=";
    for(uint32_t i=0;i<image.rows;++i)
    { printf("\n");
      //printf("\ni=%d\t",i);
      for(uint32_t j=0;j<image.cols;++j)
      {
         for(uint32_t k=0;k<3;++k)
         {
          //printf("\nj=%d\t",j);
          printf("%d\t",image.at<Vec3b>(i,j)[k]); 
         } 
       }
    }
}


int main()
{
  cv::Mat image;
  image=imread("airplane.png",IMREAD_COLOR);
  if(RESIZE_TO_DEBUG==1)
  {
    cv::resize(image,image,cv::Size(4,4));
  }  

  uint32_t m=0,n=0,total=0;
  m=(uint32_t)image.rows;
  n=(uint32_t)image.cols;
  total=m*n;
  cout<<"\nm= "<<m;
  cout<<"\nn= "<<n;
  cout<<"\ntotal= "<<total;
  
  uint8_t *diffuser;
  double b=0.00,unzero=0.000000001;
  

  /*Allocate Memory*/
  diffuser=(uint8_t*)malloc(total*3*sizeof(uint8_t));
    
  
  /*Random Parameter Generation*/
  std::random_device r;
  std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
  mt19937 seeder(seed);
  std::uniform_int_distribution<int> intGen(10, 20);
  std::uniform_real_distribution<double> realGen(unzero, 1);
  std::uniform_real_distribution<double> realGenParameter(1.07,1.4);
  auto a=realGenParameter(seeder);
  auto d=intGen(seeder);
  auto e=intGen(seeder); 
  b=0.3;
  diffuser[0]=(uint8_t)d;
  diffuser[1]=(uint8_t)e;

  
  for(uint32_t i=2;i<total*3;++i)
  {
    diffuser[i]=1+(a*diffuser[i-1]*diffuser[i-1])+(b*diffuser[i-2]);
  }
   
  cout<<"\nHenon Map=";
  for(uint32_t i=0;i<total*3;++i)
  {
    printf(" %d",diffuser[i]);
  }      
  

  return 0;
}
