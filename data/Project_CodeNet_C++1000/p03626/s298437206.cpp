#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 9999999999;
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return a;
  T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }


int main() {
  int N; cin >>N;
  string S; cin >>S;
  ll ans = 0;
  string state = "none";
  int i=0;
  if (N==1){ ans = 3; i++; }
  while (i<N){
    if (i==0){
      if (S.at(i) == S.at(i+1)){
        ans = 6; i+=2; state = "horizontal"; continue;
      }else{
        ans = 3; i++; state = "vertical"; continue;
      } 
    }
    if (i==N-1){
      if (state == "vertical") ans = ans * 2 % MOD;
      i++; break;
    }
    if (S.at(i) == S.at(i+1)){
      if (state == "horizontal") ans = ans * 3 % MOD;
      else if (state == "vertical") ans = ans * 2 % MOD;
      i+=2; state = "horizontal"; continue;
    }else{
      if (state == "vertical") ans = ans * 2 % MOD;
      i++; state = "vertical"; continue;
    }
  }

  cout <<ans <<endl;
}