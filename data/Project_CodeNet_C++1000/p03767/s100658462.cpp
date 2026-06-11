#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int64_t N;
  cin >> N;
  int64_t a[3*N];
  FOR(i,0,3*N)  cin >> a[i];
  sort(a,a+3*N,greater<int>());
  int64_t sum = 0;
  FOR(i,0,N) sum += a[2*i+1];
  cout << sum << endl;
  return 0;
}
