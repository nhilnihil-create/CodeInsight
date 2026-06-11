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
  vector<long long> A(N);
  for(int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  sort(A.rbegin(), A.rend());

  long long W = 0, H = 0;
  for(int i = 1; i < N; i++) {
    if(A[i-1] == A[i]) {
      if(!W) {
        W = A[i];
        // cout << "W: " << W << endl;
        i+=1;
      }
      else if(!H) {
        H = A[i];
        // cout << "H: " << H << endl;
        break;
      }
    }
  }

  if(W && H) {
    cout << W * H << endl;
  }
  else {
    cout << 0 << endl;
  }

  return 0;
}
