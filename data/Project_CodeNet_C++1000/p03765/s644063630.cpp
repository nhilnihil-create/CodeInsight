#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

int main(){
  string s,t;cin>>s>>t;
  int q;cin>>q;
  int sa[(int)s.size()+1]={};
  int ta[(int)t.size()+1]={};
  rep(i,s.size()){
    sa[i+1]=sa[i]+(s[i]=='A'?1:2);
  }
  rep(i,t.size()){
    ta[i+1]=ta[i]+(t[i]=='A'?1:2);
  }
  rep(i,q){
    int a,b,c,d;cin>>a>>b>>c>>d;
    if((sa[b]-sa[a-1])%3==(ta[d]-ta[c-1])%3)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}
  