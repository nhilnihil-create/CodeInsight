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
  int n;cin>>n;
  vector<ll> x(n+1);rep(i,n)cin>>x[i];
  x[n]=1e18+1;
  int l;cin>>l;
  vector<vector<int>> db(18,vector<int>(n,0));
  rep(i,n){
    int idx=upper_bound(all(x),x[i]+l)-x.begin();
    db[0][i]=--idx;
  }
  rep(i,1,18){
    rep(j,n){
      db[i][j]=db[i-1][db[i-1][j]];
    }
  }
  int q;cin>>q;
  rep(_,q){
    int a,b;cin>>a>>b;
    if(a>b)swap(a,b);
    --a;--b;
    int ctr=0;
    for(int i=17;i>=0;--i){
      int p=db[i][a];
      if(p<b){
        a=p;ctr+=(1<<i);
      }
    }
    cout<<ctr+1<<endl;
  }
}