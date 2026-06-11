#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

long long H, W;
vector<vector<long long>> cost_map(1000+1, vector<long long>(1000+1, 0));

// 最大公約数
long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
// 最小公倍数
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<long long> T(N);
  for(int i = 0; i < N; ++i) {
    cin >> T[i];
  }

  if(N > 1) {
    long long num = lcm(T[0], T[1]);
    for(int i = 2; i < N; i++) {
      num = lcm(num, T[i]);
    }
    cout << num << endl;
  }
  else {
    cout << T[0] << endl;
  }

  return 0;
}
