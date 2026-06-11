#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  int n;
  cin >> n;
  string s;
  cin >>s;
  int g=0;
  int ans=0;
  rep(i,n){
    if(s[i]=='I'){g++;}else if(s[i]=='D'){g--;}
    chmax(ans,g);
  }
  cout << ans << endl;
}