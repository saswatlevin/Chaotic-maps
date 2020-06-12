/*These two lines prevent the compiler from reading the same header file twice*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream> /*For IO*/
#include <cstdio>   /*For printf*/
#include <string>   /*For std::string()*/
#include <random>   /*For random number generation*/
#include <chrono>   /*For time*/
#include <fstream>  /*For writing to file*/ 
#include <cstdbool> /*For boolean variables*/
#include <chrono>   /*For execution time*/
#include <vector>   /*For std::vector*/
#include <typeinfo>
#include <cmath>    /*For sqrt()*/ 
#include <cstdlib>  /*For exit()*/
#include <climits>  /*For standard limits*/
#include <thrust/host_vector.h> /*For the thrust library*/
#include <thrust/transform.h>
#include <thrust/copy.h>
#include "config.hpp"

using namespace std;
using namespace std::chrono;
using namespace thrust;

namespace common
{
  
  static inline void show_ieee754 (double f);
  static inline uint32_t get_n_mantissa_bits_safe(double f,int number_of_bits);

  static inline void printArray8(uint8_t *&arr,int length);
  static inline void printArray16(uint16_t *&arr,int length);
  static inline void printArray32(uint32_t *&arr,int length);
  static inline void printArrayDouble(double *arr,int length);
  
  static inline double getRandomDouble(double lower_limit,double upper_limit);  
  static inline uint32_t getRandomUnsignedInteger32(int lower_limit,int upper_limit);


  /* formatted output of ieee-754 representation of float */
  static inline void show_ieee754 (double f)
  {
    union {
        double f;
        uint32_t u;
    } fu = { .f = f };
    int i = sizeof f * CHAR_BIT;

    printf ("  ");
    while (i--)
        printf ("%d ", BIT_RETURN(fu.u,i));

    putchar ('\n');
    printf (" |- - - - - - - - - - - - - - - - - - - - - - "
            "- - - - - - - - - -|\n");
    printf (" |s|      exp      |                  mantissa"
            "                   |\n\n");
  }

  //Print bits of an integer
  static inline void print_int_bits(int num)
  {   
    int x=1;
    for(int bit=(sizeof(int)*8)-1; bit>=0;bit--)
    {
      /*printf("%i ", num & 0x01);
      num = num >> 1;*/
      printf("%c",(num & (x << bit)) ? '1' : '0');
    }
  }

  static inline uint32_t get_n_mantissa_bits_safe(double f,int number_of_bits)
  {
    union {
        double f;
        uint32_t u;
    } fu = { .f = f };
    //int i = sizeof f * CHAR_BIT;
    int i=number_of_bits;
    uint32_t bit_store_32=0;
    uint8_t bit_store_8=0;
    uint16_t bit_store_16=0;
    
    //printf("\nBefore assigining any bits to bit_store_32=\n");
    //print_int_bits(bit_store_16);

    while (i--)
    {
        
        if(BIT_RETURN(fu.u,i)==1)
        {
            bit_store_32 |= 1 << i;
        }
        
    }
    
    
    //printf("\nAfter assigining bits to bit_store_32=\n");
    //print_int_bits(bit_store_16);
    

    //bit_store_8=(uint8_t)bit_store_32;
    return bit_store_32;
  }


  

  static inline void printArray8(uint8_t *&arr,int length)
  {
    for(int i = 0; i < length; ++i)
    {
      printf("%d",arr[i]);
    }
  }

  static inline void printArray16(uint16_t *&arr, int length)
  {
    for(int i = 0; i < length; ++i)
    {
      printf(" %d",arr[i]);
    }
  }

  static inline void printArray32(uint32_t *&arr, int length)
  {
    for(int i = 0; i < length; ++i)
    {
      printf(" %d",arr[i]);
    }
  }
  
  static inline void printArrayDouble(double *arr,int length)
  {
    for(int i = 0; i < length; ++i)
    {
      printf(" %f",arr[i]);
    }
  }

  static inline double getRandomDouble(double lower_limit,double upper_limit)
  {
     std::random_device r;
     std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
     mt19937 seeder(seed);
     //uniform_int_distribution<int> intGen(1, 32);
     uniform_real_distribution<double> realGen(lower_limit, upper_limit);   
     auto randnum=realGen(seeder);
     return (double)randnum;
  }
  
  static inline uint32_t getRandomUnsignedInteger32(int lower_limit,int upper_limit)
  {
     std::random_device r;
     std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
     mt19937 seeder(seed);
     uniform_int_distribution<uint32_t> intGen(lower_limit, upper_limit);
     auto randnum=intGen(seeder);
     return (uint32_t)randnum;
  }
  
}
#endif
