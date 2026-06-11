#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, K;
  cin >> N >> K;
  vector <int> l(N);
  rep(i,N) cin >> l[i];

  sort(all(l));
  reverse(all(l));

  int ans = 0;
  for (int i = 0; i < K; i++){
    ans += l[i];
  }
  cout << ans << endl;
}
