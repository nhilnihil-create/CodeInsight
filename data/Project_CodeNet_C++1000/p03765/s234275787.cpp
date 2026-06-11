#include <bits/stdc++.h>

using namespace std;

int numA_s[100001], numA_t[100001];

int calc_invariant(int *a, int l, int r)
{
  int A_num = a[r] - a[l - 1];
  int B_num = (r - l + 1) - A_num;
  return (A_num + B_num * 2) % 3;
}

int main()
{
  char s[100002], t[100002];
  int n, m;
  
  scanf("%s", &s[1]);
  scanf("%s", &t[1]);
  
  n = strlen(&s[1]);
  m = strlen(&t[1]);
  
  for (int i = 1; i <= n; i++) {
    numA_s[i] = (s[i] == 'A') + numA_s[i - 1];
  }
  
  for (int i = 1; i <= m; i++) {
    numA_t[i] = (t[i] == 'A') + numA_t[i - 1];
  }
  
  int q;
  scanf("%d", &q);
  
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (calc_invariant(numA_s, a, b) == calc_invariant(numA_t, c, d)) {
      printf("YES\n");
    }
    else {
      printf("NO\n");
    }
  }
  
  return 0;
}