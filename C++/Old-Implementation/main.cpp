#include "commonheader.hpp"
#include "pattern.hpp"


static inline void detectStallsAndDuplicatesInteger(unsigned int *arr,unsigned int total);



static inline void detectStallsAndDuplicatesInteger(unsigned int *arr,unsigned int total)
{
  int count_next = 0,count_stalls = 0;
  for(int i = 0; i < total - 1; ++i)
  {
    if(arr[i] == arr[i + 1])
    {
      ++count_next; 
    }
    
    if(arr[i] == arr[i + 2])
    {
      ++count_stalls; 
    }
    
  }
  
  printf("\nInteger count_next = %d",count_next);
  printf("\nInteger count_stalls = %d",count_stalls);
  
}


int main()
{
  
  unsigned int m = config::rows;
  unsigned int n = config::cols;
  unsigned int total = m * n * 3;
  cout<<"\nRows = "<<m;
  cout<<"\nColumns = "<<n;
  cout<<"\ntotal = "<<total;
  cout<<"\n";
  
  double myu = 0.00000000;
  double myu1 = 0.00000000;
  double myu2 = 0.00000000;
  double lambda1 = 0.00000000;
  double lambda2 = 0.00000000;
  double alpha = 0.00000000;
  double beta = 0.00000000;
  double r = 0.00000000;
  long double time_array[10];
  
  /*Vector Declarations*/
  double *x = (double*)calloc(total,sizeof(double));
  double *y = (double*)calloc(total,sizeof(double));
  double *x_bar = (double*)calloc(total,sizeof(double));
  double *y_bar = (double*)calloc(total,sizeof(double));
  unsigned int *arr = (unsigned int*)calloc(total,sizeof(unsigned int));
  printf("\nsizeof(double) = %ld",sizeof(double));
  printf("\nsizeof(float) = %ld",sizeof(float));  

  if(TWOD_LALM == 1)
  {
    /*LALM Parameters*/
    myu = common::getRandomDouble(MYU_LOWER_LIMIT,MYU_UPPER_LIMIT);
    x[0] = common::getRandomDouble(X_LOWER_LIMIT,X_UPPER_LIMIT);
    y[0] = common::getRandomDouble(Y_LOWER_LIMIT,Y_UPPER_LIMIT);
    x_bar[0] = 0.00;
    y_bar[0] = 0.00;
    
    auto twodlalm_start = high_resolution_clock::now();
    pattern::twodLogisticAdjustedLogisticMap(x,y,x_bar,y_bar,arr,myu,total);
    auto twodlalm_end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(twodlalm_end - twodlalm_start).count(); 
   
    cout<<"\nLALM runtime = "<<duration<< "ms";
   
   /*LALM Diagnostics*/
   //detectStallsAndDuplicatesInteger(arr,total);
   cout<<"\n";
   
               
  }
  
  if(TWOD_LASM == 1)
  {
    /*LASM Parameters*/
    myu = common::getRandomDouble(LASM_LOWER_LIMIT,LASM_UPPER_LIMIT);
    x[0] = common::getRandomDouble(X_LOWER_LIMIT,X_UPPER_LIMIT);
    y[0] = common::getRandomDouble(Y_LOWER_LIMIT,Y_UPPER_LIMIT);
    
    auto twodlasm_start = high_resolution_clock::now();
    pattern::twodLogisticAdjustedSineMap(x,y,arr,myu,total);
    auto twodlasm_end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(twodlasm_end - twodlasm_start).count(); 
    
    cout<<"\nLASM runtime = "<<duration<< "ms";
   
   /*LASM Diagnostics*/
   detectStallsAndDuplicatesInteger(arr,total);
   cout<<"\n";          
  }
  
  if(TWOD_SLMM == 1)
  {
    /*SLMM Parameters*/
    alpha = common::getRandomDouble(ALPHA_LOWER_LIMIT,ALPHA_UPPER_LIMIT);
    beta = common::getRandomDouble(BETA_LOWER_LIMIT,BETA_UPPER_LIMIT);
    x[0] = common::getRandomDouble(X_LOWER_LIMIT,X_UPPER_LIMIT);
    y[0] = common::getRandomDouble(Y_LOWER_LIMIT,Y_UPPER_LIMIT);
    
    auto twodslmm_start = high_resolution_clock::now();
    pattern::twodSineLogisticModulationMap(x,y,arr,alpha,beta,total);
    auto twodslmm_end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(twodslmm_end - twodslmm_start).count(); 
    cout<<"\nSLMM runtime = "<<duration<<" ms";
   
   /*SLMM Diagnostics*/
   detectStallsAndDuplicatesInteger(arr,total);
   cout<<"\n";        
  } 
  
  if(TWOD_LMA == 1)
  {
    /*LMA Parameters*/
    myu1 = common::getRandomDouble(MYU1_LOWER_LIMIT,MYU1_UPPER_LIMIT);
    myu2 = common::getRandomDouble(MYU2_LOWER_LIMIT,MYU2_UPPER_LIMIT);
    lambda1 = common::getRandomDouble(LAMBDA1_LOWER_LIMIT,LAMBDA1_UPPER_LIMIT);
    lambda2 = common::getRandomDouble(LAMBDA2_LOWER_LIMIT,LAMBDA2_UPPER_LIMIT);
    x[0] = common::getRandomDouble(X_LOWER_LIMIT,X_UPPER_LIMIT);
    y[0] = common::getRandomDouble(Y_LOWER_LIMIT,Y_UPPER_LIMIT);
    
    auto twodlma_start = high_resolution_clock::now();
    pattern::twodLogisticMapAdvanced(x,y,arr,myu1,myu2,lambda1,lambda2,total);
    auto twodlma_end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(twodlma_end - twodlma_start).count(); 
    cout<<"\nLMA runtime = "<<duration<<" ms";
   
   /*LMA Diagnostics*/
   detectStallsAndDuplicatesInteger(arr,total);
   cout<<"\n";           
  } 
  
  if(TWOD_LM == 1)
  {
    /*LM Parameters*/
    r = common::getRandomDouble(R_LOWER_LIMIT,R_UPPER_LIMIT);
    x[0] = common::getRandomDouble(X_LOWER_LIMIT,X_UPPER_LIMIT);
    y[0] = common::getRandomDouble(Y_LOWER_LIMIT,Y_UPPER_LIMIT);
    
    //clock_t twodlm_start = clock();
    auto lm_start = high_resolution_clock::now(); 
    
    pattern::twodLogisticMap(x,y,arr,r,total);
    
    auto lm_stop = high_resolution_clock::now(); 
    
    auto duration = duration_cast<milliseconds>(lm_stop - lm_start); 
    cout <<"\nLM runtime = "<< duration.count() <<" ms";
    //clock_t twodlm_end = clock();
    //time_array[4] = 1000.0 * (twodlm_end - twodlm_start) / CLOCKS_PER_SEC;
    //printf("\nLM runtime = %Lf ms",time_array[4]);
   
   /*LM Diagnostics*/
   //detectStallsAndDuplicatesInteger(arr,total);
   cout<<"\n";           
  } 

  if(MTS == 1)
  {
    //clock_t mt_start = clock();
    auto mt_start = high_resolution_clock::now(); 
    
    pattern::MTSequence(arr,total,1,3145828,10000);
    
    auto mt_stop = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(mt_stop - mt_start); 
    cout <<"\nMT runtime = "<< duration.count() <<" ms";
    //clock_t mt_end = clock();
    //time_array[5] = 1000.0 * (mt_end - mt_start) / CLOCKS_PER_SEC;
    //printf("\nMTS runtime = %Lf ms",time_array[5]);
     
   /*MTS Diagnostics*/
   detectStallsAndDuplicatesInteger(arr,total);
   
  }
  return 0;

}
