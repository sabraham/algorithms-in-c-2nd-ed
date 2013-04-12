#include <stdio.h>

struct fraction {
  int numerator;
  int denominator;
};

int gcd(int u, int v) {
  int t;
  while (v > 0) {
    t = u;
    u = v;
    v = t % v;
  }
  return u;
};

void reduceFraction (struct fraction *frac) {
  int g = gcd(frac->numerator, frac->denominator);
  frac->numerator /= g;
  frac->denominator /= g;
  return;
}

int main() {
  int n, d;
  scanf("%d/%d", &n, &d);
  struct fraction f = {.numerator = n, .denominator = d};
  reduceFraction(&f);
  printf("%d/%d", f.numerator, f.denominator);
}
