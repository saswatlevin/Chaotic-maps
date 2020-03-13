#include <cmath>
#include "randomfunctions.hpp"

int main()
{
	
int number=510,cnt_period=0,i=0;
int periods[12]={0,0,0,0,0,0,0,0,0,0,0,0};
double x=0.0;   

//x=fmod(sqrt(13),1);
x=getRandomNumber(LOWER_LIMIT,UPPER_LIMIT);

for(i=0;i<number;++i)
{   
    printf("\n%g",x);
    if(x==0)
    {
      
      x=x+(2*LOWER_LIMIT);      
      periods[cnt_period]=i;
      ++cnt_period;
    } 
    
  
   
        
    if(x < 0.5)
    {
        x = 2 * x;    
    }
    
    
    if (x >= 0.5)
    {
        x = 2 - 2 * x;
    }
	
}

    //printf("\ncount= %d",cnt);
    cout<<"\n\n";
    for(int i=0;i<5;++i)
    {
      cout<<periods[i]<<" ";
    }
    cout<<"\nNumber of Iterations= "<<i;
    return 0;
}
