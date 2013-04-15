#include <stdio.h>

int largest_less (int x) {
  return x <= 2 ? 0 : 1 + largest_less(x/2);
}

int main() {
  int x;
  scanf("%d", &x);
  int y = largest_less(x);
  printf("%d\n", y);
  return 0;
}
