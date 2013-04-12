#include <stdio.h>

int convert() {
  int c;
  int ret = 0;
  while ((c = getchar()) != 32) // != space
    ret = (10 * ret) + (c - 48);
  return ret;
}

int main() {
  printf("%d\n", convert());
}
