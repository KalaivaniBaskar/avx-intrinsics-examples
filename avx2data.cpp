#include <iostream>

#ifdef __AVX__
  #include <immintrin.h>
#else
  #warning No AVX support - will not compile
#endif

int main() {
    // Initialize the vector
    __m256i hello = _mm256_set_epi32(1, 2, 3, 4, 5, 6, 7, 8);

    // Extract the individual elements from the vector and print them
    
    // Ensure proper alignment for the array
    // __attribute__ ((aligned (32))) int elements[8]; for .C 
    alignas(32) int elements[8];

    _mm256_store_si256((__m256i*)elements, hello);

    // Print the elements
    for (int i = 0; i < 8; ++i) {
        printf("%d ", elements[i]);
    }
    std::cout<< "\n";
    return 0;
}
