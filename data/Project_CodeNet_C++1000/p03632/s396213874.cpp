#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  if (B < C || D < A) cout << 0 << endl;
  else cout << min(B, D) - max(A, C) << endl;
}
