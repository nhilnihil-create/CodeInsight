#include<iostream>
#include<queue>
#include<bitset>
#include<algorithm>
#include<climits>
#include<vector>
#include<deque>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define fill(x,y) memset(x,y,sizeof(x))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define dump(a) rep(i,a.size()){ cout<<a[i]<<" "; } cout<<endl;
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define INF INT_MAX/3
#define EPS 1e-7

/*
 *
 */

int main(){
  ll n,m;
  ll x[100001];
  ll y[100001];
  cin>>n>>m;
  const ll B = 1e9+7;

  ll s=0,t=0;
  rep(i,n){
    cin>>x[i];
    s = (s + x[i]*(2*i-n+1))%B;
  }
  rep(i,m){
    cin>>y[i];
    t = (t + y[i]*(2*i-m+1))%B;
  }
  cout<<(s*t)%B<<endl;
  return 0;
}
