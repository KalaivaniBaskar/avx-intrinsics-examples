#include <stdio.h>
#include <immintrin.h>

int main() {
    // Initialize the vector
    __m256i hello = _mm256_set1_epi32(9);

    // Extract the individual elements from the vector and print them
    
    // Ensure proper alignment for the array
    __attribute__ ((aligned (32))) int elements[8];
    //alignas(32) int elements[8]; is for .CPP

    _mm256_store_si256((__m256i*)elements, hello);

    // Print the elements
    for (int i = 0; i < 8; ++i) {
        printf("%d ", elements[i]);
    }

    return 0;
}
