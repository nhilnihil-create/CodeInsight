#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
/*
void chmin(ll a, ll b){if (a>b){a = b; return true;}return false;}
void chmax(ll a, ll b){if (a<b){a = b; return true;}return false;}
*/

const ll MOD = 1000000007;
const ll INF = 9999999999;

int main() {
  int n; cin >>n;
  vector<int> A(100001, 0);
  // int buf;
  for (int i=0; i<n; i++){
    int buf; cin >>buf;
    A.at(buf)++;
  }
  int ans = 0;
  bool ok = false;
  for (int i=0; i<100001; i++){
    if (A.at(i) == 0) continue;
    if (A.at(i) % 2 == 1) ans++;
    else{
      if (ok){
        ans+=2; ok = false;
      }else{
        ok = true;
      }
    }
  }
  cout <<ans <<endl;
}