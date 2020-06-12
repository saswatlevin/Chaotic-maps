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
  unsigned int total = m;
  unsigned int count_unequal = 0;
  cout<<"\nRows = "<<m;
  cout<<"\nColumns = "<<n;
  cout<<"\ntotal = "<<total;
  cout<<"\n";
  
  double myu = 0;
  double myu1 = 0;
  double myu2 = 0;
  double lambda1 = 0;
  double lambda2 = 0;
  double alpha = 0;
  double beta = 0;
  double r = 0;
   
  double X = 0;
  double Y = 0;
  double X_BAR = 0;
  double Y_BAR = 0;
  
  long double time_array[10];
  
  /*Vector Declarations*/
  double *x = (double*)calloc(total,sizeof(double));
  double *x_dash = (double*)calloc(total,sizeof(double));
  double *y = (double*)calloc(total,sizeof(double));
  double *x_bar = (double*)calloc(total,sizeof(double));
  double *y_bar = (double*)calloc(total,sizeof(double));
  unsigned int *arr = (unsigned int*)calloc(total,sizeof(unsigned int));
  int *arr1 = (int*)calloc(total,sizeof(int));
  
  int exp = 1000000000;
  
  std::vector<int> random_vec(total);
  
  printf("\nsizeof(double) = %ld",sizeof(double));
  printf("\nsizeof(float) = %ld",sizeof(float));  
  
  if(TWOD_LALM == 1)
  {
    count_unequal = 0;
    
    /*LALM Parameters*/
    myu = common::getRandomDouble(MYU_LOWER_LIMIT,MYU_UPPER_LIMIT);
    x[0] = common::getRandomDouble(X_LOWER_LIMIT,X_UPPER_LIMIT);
    y[0] = common::getRandomDouble(Y_LOWER_LIMIT,Y_UPPER_LIMIT);
    
    X = x[0];
    Y = y[0];
    X_BAR = 0.00;
    Y_BAR = 0.00;
    
    auto twodlalm_start = steady_clock::now();
    pattern::twodLogisticAdjustedLogisticMap(x,y,x_bar,y_bar,arr,myu,total);
    auto twodlalm_end = steady_clock::now();
    auto duration = duration_cast<microseconds>(twodlalm_end - twodlalm_start).count(); 
    
    cout<<"\nOld LALM runtime = "<<duration<< "us";
    
    for(int i = 0; i < total - 1; ++i)
    {
      pattern::twodLALM(X_BAR,Y_BAR,X,Y,myu);
      x_dash[i + 1] = X;
    }
    
    twodlalm_start = steady_clock::now();
    for(int i = 0; i < total - 1; ++i)
    {
      pattern::twodLASM(X,Y,myu);
      random_vec[i + 1] = (int)(X * exp) % m;
       
    } 
    cout<<"\nNew LALM runtime = "<<(duration_cast<microseconds>(steady_clock::now() - twodlalm_start).count())<<" us"; 
   
   for(int i = 0; i < total - 1; ++i)
   {
     if(x_dash[i] != x[i])
     {
       ++count_unequal;
     }
   }
   
   cout<<"\ncount_unequal in LALM = "<<count_unequal;
   
   /*LALM Diagnostics*/
   detectStallsAndDuplicatesInteger(arr,total);
   cout<<"\n";          
  }
  
  
  if(TWOD_LASM == 1)
  {
    count_unequal = 0;
    
    /*LASM Parameters*/
    myu = common::getRandomDouble(LASM_LOWER_LIMIT,LASM_UPPER_LIMIT);
    x[0] = common::getRandomDouble(X_LOWER_LIMIT,X_UPPER_LIMIT);
    y[0] = common::getRandomDouble(Y_LOWER_LIMIT,Y_UPPER_LIMIT);
    
    X = x[0];
    Y = y[0];
    
    auto twodlasm_start = steady_clock::now();
    pattern::twodLogisticAdjustedSineMap(x,y,arr,myu,total);
    auto twodlasm_end = steady_clock::now();
    auto duration = duration_cast<microseconds>(twodlasm_end - twodlasm_start).count(); 
    
    cout<<"\nOld LASM runtime = "<<duration<< "us";
    
    for(int i = 0; i < total - 1; ++i)
    {
      pattern::twodLASM(X,Y,myu);
      x_dash[i + 1] = X;
    }
    
    twodlasm_start = steady_clock::now();
    for(int i = 0; i < total - 1; ++i)
    {
      pattern::twodLASM(X,Y,myu);
      random_vec[i + 1] = (int)(X * exp) % m;
       
    } 
    cout<<"\nNew LASM runtime = "<<(duration_cast<microseconds>(steady_clock::now() - twodlasm_start).count())<<" us"; 
   
   for(int i = 0; i < total - 1; ++i)
   {
     if(x_dash[i] != x[i])
     {
       ++count_unequal;
     }
   }
   
   cout<<"\ncount_unequal in LASM = "<<count_unequal;
   
   /*LASM Diagnostics*/
   detectStallsAndDuplicatesInteger(arr,total);
   cout<<"\n";          
  }
  
  if(TWOD_SLMM == 1)
  {
    count_unequal = 0;
    
    /*SLMM Parameters*/
    alpha = common::getRandomDouble(ALPHA_LOWER_LIMIT,ALPHA_UPPER_LIMIT);
    beta = common::getRandomDouble(BETA_LOWER_LIMIT,BETA_UPPER_LIMIT);
    x[0] = common::getRandomDouble(X_LOWER_LIMIT,X_UPPER_LIMIT);
    y[0] = common::getRandomDouble(Y_LOWER_LIMIT,Y_UPPER_LIMIT);
    
    X = x[0];
    Y = y[0];
    
    auto twodslmm_start = steady_clock::now();
    pattern::twodSineLogisticModulationMap(x,y,arr,alpha,beta,total);
    auto twodslmm_end = steady_clock::now();
    auto duration = duration_cast<microseconds>(twodslmm_end - twodslmm_start).count(); 
    cout<<"\nOld SLMM runtime = "<<duration<<" us";
    
    for(int i = 0; i < total - 1; ++i)
    {
      pattern::twodSLMM(X,Y,alpha,beta);
      x_dash[i + 1] = X;
    }
    
    twodslmm_start = steady_clock::now();
    for(int i = 0; i < total - 1; ++i)
    {
      pattern::twodSLMM(X,Y,alpha,beta);
      random_vec[i + 1] = (int)(X * exp) % m;
       
    } 
    cout<<"\nNew SLMM runtime = "<<(duration_cast<microseconds>(steady_clock::now() - twodslmm_start).count())<<" us"; 
   
   for(int i = 0; i < total - 1; ++i)
   {
     if(x_dash[i] != x[i])
     {
       ++count_unequal;
     }
   }
    
   cout<<"\ncount_unequal in SLMM = "<<count_unequal;
   /*SLMM Diagnostics*/
   detectStallsAndDuplicatesInteger(arr,total);
   cout<<"\n";        
  } 
  
  
  if(TWOD_LM == 1)
  {
    count_unequal = 0;
    
    /*LM Parameters*/
    r = common::getRandomDouble(R_LOWER_LIMIT,R_UPPER_LIMIT);
    x[0] = common::getRandomDouble(X_LOWER_LIMIT,X_UPPER_LIMIT);
    y[0] = common::getRandomDouble(Y_LOWER_LIMIT,Y_UPPER_LIMIT);
    
    X = x[0];
    Y = y[0];
    const double R = r;
    //clock_t twodlm_start = clock();
    auto lm_start = steady_clock::now(); 
    
    pattern::twodLogisticMap(x,y,arr,r,total);
    
    auto lm_stop = steady_clock::now(); 
    
    auto duration = duration_cast<microseconds>(lm_stop - lm_start).count();
    printf("\nOld LM duration = %ld us", duration); 
   
   
   for(int i = 0; i < total - 1; ++i)
   {
     pattern::twodLM(X,Y,R);
     x_dash[i + 1] = X; 
   }
    
   lm_start = steady_clock::now();
   
   /*Checking if new implementation is functioning correctly*/
   for(int i = 0; i < total - 1; ++i)
   {
     
     pattern::twodLM(X,Y,R);
     random_vec[i + 1] = (int)(X * exp) % m; 
     
   }
   //lm_stop = steady_clock::now();
   duration = duration_cast<microseconds>(steady_clock::now() - lm_stop).count();
   printf("\nNew LM duration = %ld us", duration);   
   
   for(int i = 0; i < total - 1; ++i)
   {
     if(x_dash[i] != x[i])
     {
       ++count_unequal;
     }
   }
   
   //cout<<"\nx = ";
   //common::printArrayDouble(x,total);
   //cout<<"\nx_dash = ";
   //common::printArrayDouble(x_dash,total);
   
   /*LM Diagnostics*/  
   detectStallsAndDuplicatesInteger(arr,total);
   cout<<"\ncount_unequal in LM = "<<count_unequal;
   cout<<"\n";           
  } 

  if(MTS == 1)
  {
    //clock_t mt_start = clock();
    auto mt_start = high_resolution_clock::now(); 
    
    pattern::MTSequence(arr,total,1,3145828,10000);
    
    auto mt_stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(mt_stop - mt_start); 
    cout <<"\nMT runtime = "<< duration.count() <<" us";
    //clock_t mt_end = clock();
    //time_array[5] = 1000.0 * (mt_end - mt_start) / CLOCKS_PER_SEC;
    //printf("\nMTS runtime = %Lf us",time_array[5]);
     
   /*MTS Diagnostics*/
   detectStallsAndDuplicatesInteger(arr,total);
   
  }
  return 0;

}
