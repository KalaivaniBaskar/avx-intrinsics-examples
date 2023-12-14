/* Construct a 256-bit vector from 4 64-bit doubles. Add it to itself
 * and print the result.
 */

// A complete compilation command looks like below - gcc for c pgm compilation, g++ for c++ pgms, -mavx2 flag for using avx2 instruction set, -mavx for avx set.
// gcc foo.c -mavx2

#include <stdio.h>
#include <immintrin.h>

int main() {

  __m256i hello = _mm256_set_epi32(1,2,3,4,5,6,7,8);
  // Construction from scalars or literals.
  __m256d a = _mm256_set_pd(1.0, 2.0, 3.0, 4.0);

  // Does GCC generate the correct mov, or (better yet) elide the copy
  // and pass two of the same register into the add? Let's look at the assembly.
  __m256d b = a;

  // Add the two vectors, interpreting the bits as 4 double-precision
  // floats.
  __m256d c = _mm256_add_pd(a, b);

  // Do we ever touch DRAM or will these four be registers?
  __attribute__ ((aligned (32))) double output[4];
  _mm256_store_pd(output, c);

  printf("%f %f %f %f\n",
         output[0], output[1], output[2], output[3]);
  printf("\n %lld", hello[0]); 


// for hello vector
  // Extract the individual elements from the copied vector
    int elements[8];
    _mm256_store_si256((__m256i*)elements, hello);

    // Print the copied elements
    for (int i = 0; i < 8; ++i) {
        printf("%d ", elements[i]);
    }
 
  return 0;
}
