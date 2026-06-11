#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  string s,t;
  cin>>s>>t;
  int count=0;
  for(int i=N;i<=2*N;i++){
    int d=2*N-i;
  
  if(d>0&&s.substr(N-d)==t.substr(0,2*N-i)){cout<<i<<endl;return 0;}
  else if(d==0){cout<<2*N<<endl;}
  }
  
  return 0;}