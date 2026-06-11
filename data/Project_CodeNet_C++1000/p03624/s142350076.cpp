#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;
int64_t dp[2005];
int main() {
  string s;
  cin>>s;
  for(char c='a';c<='z';c++){
    bool ok=true;
    for(int i=0;i<s.size();i++){
      if(s[i]==c){ok=false;}
    }
    if(ok){cout<<c<<endl;return 0;}
  }
  cout<<"None"<<endl;
  return 0;
}