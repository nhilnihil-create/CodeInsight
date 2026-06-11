#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC043 A - キャンディーとN人の子供イージー
// 2020.06.15

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int ans = N*(N+1)/2;
  cout << ans << endl;
}