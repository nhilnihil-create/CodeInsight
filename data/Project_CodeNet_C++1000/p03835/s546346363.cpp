#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int main() {
  int K,S;
  cin >> K >> S;

  int ans = 0;

  rep(i,K+1)rep(j,K+1){
    int t = i + j;
    if(S - t >= 0 && S - t <= K) ans++;

  }

  cout << ans << endl;

	return 0;
}

