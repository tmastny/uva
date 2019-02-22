#include <stdio.h>

int n3_add_1(int n) {
  if (n == 1) {
    return 1;
  }

  if (n % 2 == 1) {
    return n3_add_1(3 * n + 1) + 1;
  }

  return n3_add_1(n / 2) + 1;
}

int main() {
  int i, j, cycle;
  int smaller, larger;

  int max = 0;
  while (scanf("%d %d", &i, &j) != EOF) {
    smaller = i;
    larger = j;
    if (i > j) {
      smaller = j;
      larger = i;
    }

    for (int k = smaller; k <= larger; k++) {
      cycle = n3_add_1(k);
      if (cycle > max) {
        max = cycle;
      }
    }
    printf("%d %d %d\n", i, j, max);
    max = 0;
  }
}
