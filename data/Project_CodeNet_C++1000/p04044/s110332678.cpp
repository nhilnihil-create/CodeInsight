#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  int n,l;
  cin>>n>>l;
  vector<string>s(n);
  rep(i,n)cin>>s[i];
  sort(s.begin(),s.end());
  string ans="";
  rep(i,n)ans=ans+s[i];
  cout<<ans<<endl;
    
    
  return 0;
}
