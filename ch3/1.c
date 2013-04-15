#include <stdio.h>

int gcd(int u, int v) {
  int t;
  while (v > 0) {
    t = u;
    u = v;
    v = t % v;
  }
  return u;
}

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  int a[m][n];
  // set upper and lower triangles
  for (int i = 0; i < m; ++i)
    for (int j = i + 1; j < n; ++j) {
      a[i][j] = 1 ? (gcd(i, j) == 1) : 0;
      a[j][i] = a[i][j];
    }
  // set diagonal
  for (int i = 0; i < m; ++i) a[i][i] = 1;
  // print
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) 
      printf("%d ", a[i][j]);
    printf("\n");
  }
  return 0;
}
