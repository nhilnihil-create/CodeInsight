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
  string s; cin >>s;
  int n = s.size();
  int G = 0, P = 0;
  for (int i=0; i<n; i++){
    if (s.at(i) == 'g'){
      G++;
    }else{
      P++;
    }
  }
  int ans = (G-P)/2;
  cout <<ans <<endl;
}