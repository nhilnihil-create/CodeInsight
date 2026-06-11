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
  vector<int> ans(2, -1);
  if (s.at(0) == s.at(1)){
    ans.at(0) = 1, ans.at(1) = 2;
  }
  for (int i=2; i<n; i++){
    int ai = i-2, bi = i-1;
    char a = s.at(ai), b = s.at(bi);
    char c = s.at(i);
    if (a == c){
      ans.at(0) = ai+1, ans.at(1) = i+1;
      break;
    }else if (b == c){
      ans.at(0) = bi+1, ans.at(1) = i+1;
      break;
    }
  }
  cout <<ans.at(0) <<" " <<ans.at(1) <<endl;
}