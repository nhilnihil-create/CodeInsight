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
  int H, W; cin >> H >> W;
  vector<string> S(H);
  REP(i, H){
    cin >> S[i];
  }
  REP(i, W+2){
    cout << "#";
  }
  cout << endl;
  REP(i, H){
    cout << "#" << S[i] << "#" << endl;
  }
  REP(i, W+2){
    cout << "#";
  }
  cout << endl; 
}