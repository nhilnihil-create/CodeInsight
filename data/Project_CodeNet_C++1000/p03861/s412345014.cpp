#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;
int main() {
  int64_t a,b,x;
  cin>>a>>b>>x;
  if(a==0){cout<<b/x+1<<endl;}
  else{cout<<b/x-(a-1)/x<<endl;}
  return 0;
}