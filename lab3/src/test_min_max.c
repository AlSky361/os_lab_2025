#include <stdio.h>
#include <stdlib.h>

#include "find_min_max.h"
#include "utils.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
  int seeds[] = {1, 40, 41, 42, 43};
  int sizes[] = {1, 5, 10, 100, 1000, 10000};

  int num_seeds = sizeof(seeds) / sizeof(seeds[0]);
  int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

  int total = 0;
  int passed = 0;

  for (int s = 0; s < num_seeds; s++) {
    for (int n = 0; n < num_sizes; n++) {
      int seed = seeds[s];
      int size = sizes[n];

      int *array = malloc(size * sizeof(int));
      GenerateArray(array, size, seed);

      struct MinMax my_result = GetMinMax(array, 0, size);

      int std_min = array[0];
      int std_max = array[0];
      for (int i = 1; i < size; i++) {
        std_min = MIN(std_min, array[i]);
        std_max = MAX(std_max, array[i]);
      }

      total++;
      int ok = (my_result.min == std_min) && (my_result.max == std_max);
      if (ok) {
        passed++;
      } else {
        printf("seed=%-5d size=%-6d GetMinMax: min=%-12d max=%-12d  MIN/MAX: min=%-12d max=%-12d  MISMATCH\n",
               seed, size, my_result.min, my_result.max, std_min, std_max);
      }

      free(array);
    }
  }

  if (passed == total) {
    printf("All tests passed (%d/%d)\n", passed, total);
  } else {
    printf("\n%d/%d tests passed\n", passed, total);
  }

  return (passed == total) ? 0 : 1;
}
