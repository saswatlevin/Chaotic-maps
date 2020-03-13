#ifndef RANDOMFUNCTIONS_H
#define RANDOMFUNCTIONS_H

#include <iostream>
#include <ctime>
#include <cstdio>
#include <random>
#include <chrono>
#include <cstdint>
#define LOWER_LIMIT 0.000001
#define UPPER_LIMIT 0.09

using namespace std;

double getRandomNumber(double lower_limit,double upper_limit);

double getRandomNumber(double lower_limit,double upper_limit)
{
  
   std::random_device r;
   std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
   mt19937 seeder(seed);
   //uniform_int_distribution<int> intGen(1, 32);
   uniform_real_distribution<double> realGen(lower_limit, upper_limit);   
   auto randnum=realGen(seeder);
   return (double)randnum;
}

#endif
