#include <iostream>    /*For IO*/
#include <cstdint>     /*For standard variable types*/
#include <random>      /*For random number generation*/
#include <cstdio> /*For printf()*/
#include <cstdlib>/*for malloc()*/
#include <cmath>  /*for fabs()*/

using namespace std;

void henonMap(double *&x_vec,double *&y_vec,double a,double b,uint16_t total);
void checkOutOfBounds(double value);

void henonMap(double *&x_vec,double *&y_vec,double a,double b,uint16_t total)
{
  
  for(uint32_t i=2;i<total;++i)
  { 

    x_vec[i]=1-1.4*(x_vec[i-1]*x_vec[i-1])+b*x_vec[i-2];
    
    
  }
   
}

void checkOutOfBounds(double value)
{
  if(value>=1.0||value<=-1.0)
  {
    cout<<"\nOUT OF BOUNDS!!";
    
  }
}

int main()
{
  /*cv::Mat image;
  image=imread("airplane.png",IMREAD_COLOR);
  if(RESIZE_TO_DEBUG==1)
  {
    cv::resize(image,image,cv::Size(2,2));
  }  

  uint32_t m=0,n=0,total=0;
  m=(uint32_t)image.rows;
  n=(uint32_t)image.cols;
  total=m*n;*/
  //cout<<"\nm= "<<m;
  //cout<<"\nn= "<<n;
  //cout<<"\ntotal= "<<total;
  
  uint16_t size=50;
  double *x_vec,*y_vec;
  //uint8_t *img_vec;
  double a=0.00, b=0.00,unzero=0.000000001;
  

  /*Allocate Memory*/
  x_vec=(double*)malloc(size*sizeof(double));
  y_vec=(double*)malloc(size*sizeof(double));

  //img_vec=(uint8_t*)malloc(total*3*sizeof(uint8_t));  
  
  /*Random Parameter Generation*/
 
  //auto a=realGenParameter(seeder);
  a=1.4;
  b=0.3;
  
  /*Generating xor_vec*/
  x_vec[0]=0.0;
  y_vec[1]=0.0;
  henonMap(x_vec,y_vec,a,b,size);
  
  printf("\nx_vec=");
  for(int i=0;i<size;++i)
  {
    printf("\n%F",x_vec[i]);
  }

  /*printf("\n\ny_vec=");
  for(int i=0;i<size;++i)
  {
    printf("\n%F",y_vec[i]);
  }*/   
  

  
        
  

  return 0;
}
