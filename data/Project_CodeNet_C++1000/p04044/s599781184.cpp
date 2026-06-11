#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, L;
  cin >> N >> L;
  vector <string> S(N);
  rep(i,N) cin >> S[i];

  sort(all(S));
  rep(i,N){
    cout << S[i];
  }
  cout << endl;
}
