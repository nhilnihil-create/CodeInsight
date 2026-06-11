#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int n, k;
int a[5000];
bitset<5001> DP[5001];
bitset<5001> DQ[5001];

void pre() {
  DP[0][0] = true;
  DQ[0][0] = true;
  for (int i = 0; i < n; ++i) {
    DP[i + 1] = DP[i] | (DP[i] << a[i]);
    DQ[i + 1] = DQ[i] | (DQ[i] << a[n - 1 - i]);
  }
}

bool no_need(int i) {
  bitset<5001> x = DP[i];
  bitset<5001> y = DQ[n - 1 - i];
  
  const int lo = max(0, k - a[i]);
  const int hi = k;
  
  vector<int> p(k + 2);
  for (int i = 0; i <= k; ++i) {
    p[i + 1] = p[i] + y[i];
  }
  
  for (int i = 0; i < hi; ++i) {
    if (!x[i]) continue;
    int l = max(0, lo - i);
    int r = hi - i;
    if (p[r] - p[l] > 0) return false; 
  }
  return true;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  pre();
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += no_need(i);
  }
  cout << sum << endl;
}