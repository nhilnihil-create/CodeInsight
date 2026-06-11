#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

const int mod=1e9+7;
 
int main(){
  ll i,o,t,j,l,s,z;cin>>i>>o>>t>>j>>l>>s>>z;
  ll ans=0;
  ans+=o;
  ll A=i/2*2+j/2*2+l/2*2;
  ll B=0;
  if(i>0&&j>0&&l>0){
    --i;--j;--l;
    B=i/2*2+j/2*2+l/2*2+3;
  }
  cout<<ans+max(A,B)<<endl;
}