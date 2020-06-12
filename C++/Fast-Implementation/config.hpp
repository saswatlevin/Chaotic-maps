#ifndef CONFIG_H /*These two lines are to ensure no errors if the header file is included twice*/
#define CONFIG_H
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
  //define something for Windows (32-bit and 64-bit, this part is common)
 std::string separator;
  #ifdef _WIN64
    //define something for Windows (64-bit only)
    separator = "\\";
  #else
    //define something for Windows (32-bit only)
    separator = "\\";
  #endif

#elif __linux__
  std::string separator = "/";
  
 
#elif __unix__ // all unices not caught above
  // Unix
   std::string separator = "/";
  
#elif defined(_POSIX_VERSION)
  // POSIX
  std::string separator = "/";

#else
  #error "Unknown compiler"
#endif


#define TWOD_LALM                    1
#define TWOD_LASM                    1
#define TWOD_SLMM                    1
#define TWOD_LM                      1
#define MTS                          1

#define LOWER_LIMIT                  0.000001
#define UPPER_LIMIT                  0.09

#define SEED_LOWER_LIMIT             3000000
#define SEED_UPPER_LIMIT             1073741824       

#define X_LOWER_LIMIT                0.10000000
#define X_UPPER_LIMIT                0.90000000

#define Y_LOWER_LIMIT                0.10000000
#define Y_UPPER_LIMIT                0.90000000

#define MYU_LOWER_LIMIT              0.50000000
#define MYU_UPPER_LIMIT              0.90000000

#define LASM_LOWER_LIMIT             0.40000000
#define LASM_UPPER_LIMIT             0.90000000

#define MYU1_LOWER_LIMIT             3.01000000
#define MYU1_UPPER_LIMIT             3.29000000

#define MYU2_LOWER_LIMIT             3.01000000
#define MYU2_UPPER_LIMIT             3.30000000

#define LAMBDA1_LOWER_LIMIT          0.16000000
#define LAMBDA1_UPPER_LIMIT          0.21000000

#define LAMBDA2_LOWER_LIMIT          0.14000000
#define LAMBDA2_UPPER_LIMIT          0.15000000

#define ALPHA_LOWER_LIMIT            0.90500000
#define ALPHA_UPPER_LIMIT            0.99500000

#define BETA_LOWER_LIMIT             2.97000000
#define BETA_UPPER_LIMIT             3.00000000

#define R_LOWER_LIMIT                1.11000000
#define R_UPPER_LIMIT                1.19000000
#define NUMBER_OF_BITS               31
#define EXP                          1000000000
#define BIT_RETURN(A,LOC) (( (A >> LOC ) & 0x1) ? 1:0)

namespace config
{
  
  uint32_t rows = 1024;
  uint32_t cols = 1024;
  
  int lower_limit = 1;
  int upper_limit = rows + 1;

  enum class ChaoticMap
  {
    TwoDLogisticMap,
    TwoDLogisticMapAdvanced,
    TwoDLogisticAdjustedSineMap,
    TwoDSineLogisticModulationMap,
    TwoDLogisticAdjustedLogisticMap
  };
  
  ChaoticMap chaotic_map = ChaoticMap::TwoDSineLogisticModulationMap;
  
    
}  

#endif
