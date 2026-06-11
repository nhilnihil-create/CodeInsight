#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S; cin >> S;
  int N = S.size();
  REP(i, N-1){
    if(S[i] == S[i+1]){
      cout << i+1 << " " << i+2 << endl;
      return 0;
    }
  }
  REP(i, N-2){
    if(S[i] == S[i+2]){
      cout << i+1 << " " << i+3 << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;
}