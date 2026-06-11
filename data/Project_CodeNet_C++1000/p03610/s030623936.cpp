#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const long long mod=998244353;

int main(){
  string s;
  cin>>s;
  string ans;
  for(int i=0;i<s.size();i++){
    if((i+1)%2==1){ans+=s[i];}
  }
  cout<<ans<<endl;
  return 0;                       
}