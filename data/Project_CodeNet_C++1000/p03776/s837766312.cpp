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

ll c[51][51];

void makec(){
  rep(i,51) rep(j,i+1){
    if(i==0)c[i][j]=1;
    else if(j==0||j==i)c[i][j]=1;
    else c[i][j]=c[i-1][j-1]+c[i-1][j];
  }
  return;
}

int main(){
  int n,a,b;cin>>n>>a>>b;
  ll v[n];rep(i,n)cin>>v[i];
  sort(v,v+n,greater<ll>());
  makec();
  ll ans=0;
  if(v[0]==v[a-1]){
    int ctr=0;
    rep(i,n){
      if(v[i]==v[0])ctr++;
    }
    rep(i,a,b+1){
      ans+=c[ctr][i];
    }
  }
  else{
    ll p=v[a-1];
    int forward=0;
    rep(i,a-1){
      if(v[i]==p)forward++;
    }
    int backward=0;
    rep(i,a-1,n){
      if(v[i]==p)backward++;
    }
    ans=c[forward+backward][forward+1];
  }
  long double res=0;
  rep(i,a)res+=v[i];
  cout<<setprecision(25)<<res/(double)a<<endl;
  cout<<ans<<endl;
}
