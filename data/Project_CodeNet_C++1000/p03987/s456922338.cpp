#include <bits/stdc++.h>

const int N = 200001;

int n, indez[N], value[N];

int main()
{
  while (scanf("%d", &n) == 1) {
    long long result = 0;
    long long sum = 0;
    int t = 1;
    indez[0] = -1;
    value[0] = 0;
    for (int i = 0, a; i < n; ++ i) {
      scanf("%d", &a);
      while (value[t - 1] > a) {
        t --;
        sum -= 1LL * value[t] * (indez[t] - indez[t - 1]);
      }
      indez[t] = i;
      value[t] = a;
      sum += 1LL * a * (i - indez[t - 1]);
      t ++;
      result += sum;
    }
    printf("%lld\n", result);
  }
}
