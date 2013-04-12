#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char *binary(int x) {
  size_t num_bits = sizeof(int) * CHAR_BIT;
  char *res = malloc(num_bits + 1); // bits + null termination
  res[num_bits] = 0; // null terminate string
  for(; num_bits--; x >>= 1) res[num_bits] = x & 1 ? '1' : '0';
  return res;
}

int main() {
  int x;
  scanf("%d", &x);
  printf("%s\n", binary(x));
}
