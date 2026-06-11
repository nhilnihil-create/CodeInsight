#include <bits/stdc++.h>
#define N (long long)(1e9 + 7)
#define MAX 500000
using namespace std;
 
long long factorial[MAX] = {0}, finverse[MAX] = {0},
          inverse[MAX] = {0};
 
void smodfact() {
  factorial[0] = factorial[1] = 1;
  finverse[0] = finverse[1] = 1;
  inverse[1] = 1;
  for(int i = 2; i < MAX; ++i) {
    factorial[i] = factorial[i - 1] * i % N;
    inverse[i] = N - (inverse[N % i] * (N / i)) % N;
    finverse[i] = finverse[i - 1] * inverse[i] % N;
  }
}
 
long long calccomb(long long n, long long k) {
  if(n == k && n == 0) return 1;
  if(n < 0 || k < 0 || n < k) return 0;
  return factorial[n] * finverse[k] % N * finverse[n - k] %
         N;
}
long long h, w, a, b;
 
long long solve();
 
int main() {
  smodfact();
  cin >> h >> w >> a >> b;
  cout << solve() << endl;
  return 0;
}
 
long long solve() {
  long long ans = 0, bf = 0, now;
  for(long long i = b; i < w; ++i) {
    now = calccomb(h - 1 - a + i, i) - bf;
    while(now < 0) now += N;
    ans += now * calccomb(a + w - 1 - i, a) % N;
    ans %= N;
    bf = calccomb(h - 1 - a + i, i);
  }
  return ans;
}