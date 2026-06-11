#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF=1e18+1;
const int mod = 1000000007;

int main() {
  string s;
  cin>>s;
  if(s[0]==s[2]){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
  return 0;
}