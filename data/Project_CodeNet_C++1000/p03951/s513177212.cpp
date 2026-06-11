#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int mod=1e9+7;
const int64_t INF=1e18;

int main() {
  int N;
  string s,t;
  cin>>N>>s>>t;
  string r=s;
  reverse(r.begin(),r.end());
  for(int l=N;l>=0;l--){ 
    string k=r.substr(0,l);
    reverse(k.begin(),k.end());
    if(k==t.substr(0,l)){cout<<2*N-l<<endl;return 0;}
  }
  return 0;  
}