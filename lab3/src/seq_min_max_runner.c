#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s seed array_size\n", argv[0]);
    return 1;
  }

  execl("./sequential_min_max", "sequential_min_max", argv[1], argv[2],
        (char *)NULL);

  perror("execl failed");
  return 1;
}
