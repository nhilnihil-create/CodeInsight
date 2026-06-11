#include <bits/stdc++.h>
#define lol long long
template<class A,class B>inline bool chmax(A &a,const B &b){return(b>a&&(a=b,true));}
template<class A,class B>inline bool chmin(A &a,const B &b){return(b<a&&(a=b,true));}
using namespace std;
lol mod=1e9+7;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;cin >>n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin >>a[i];
  b=a;
  sort(b.begin(),b.end());
  set<int> s;
  for(int i=0;i<n;i+=2){
    s.insert(b[i]);
  }
  int ans=0;
  for(int i=0;i<n;i+=2){
    if(s.find(a[i])==s.end()) ans++;
  }
  cout <<ans<<'\n';
  return (0);
}