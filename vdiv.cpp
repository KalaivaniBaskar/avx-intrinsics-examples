#include <iostream>

#ifdef __AVX2__
  #include <immintrin.h>
#else
  #warning No AVX support - will not compile
#endif

// to compile this pgm and run: 
//g++ --std=c++14 -O2 -mavx avx.cpp -o avx
//./avx

int main(int argc, char **argv)
{
    __m256 a = _mm256_set_ps(8.2, 7.0, 6.0, 5.0, 
                             4.0, 3.0, 2.0, 1.0);
    __m256 b = _mm256_set_ps(18.2, 17.0, 16.0, 15.0, 
                             14.0, 13.0, 12.0, 11.0);

    __m256 c = _mm256_div_ps(b , a);

    float d[8];
    _mm256_storeu_ps(d, c); // unaligned ip
    
    alignas(32) float e[8];
    _mm256_store_ps(e, c); // requires aligned ip 

    std::cout << "result equals " << d[0] << "," << d[1]
              << "," << d[2] << "," << d[3] << ","
              << d[4] << "," << d[5] << "," << d[6] << ","
              << d[7] << std::endl;

// note the order is not aligned in d
// result equals 12,14,16,18,20,22,24,26 

//lets check for e
std::cout << "result equals " << e[0] << "," << e[1]
              << "," << e[2] << "," << e[3] << ","
              << e[4] << "," << e[5] << "," << e[6] << ","
              << e[7] << std::endl;
    return 0;
}
