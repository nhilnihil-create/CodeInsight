#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC051 B - Sum of Three Integers
// 2020.06.13

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int K, S; cin >> K >> S;
  int ans = 0;
  REP(i, K+1){
    REP(j, K+1){
      if(S-i-j >= 0 && S-i-j <= K){
        ans++;
      }
    }
  }
  cout << ans << endl;
}