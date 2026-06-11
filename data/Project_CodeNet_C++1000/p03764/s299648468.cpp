#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, M;
  cin>>N>>M;
  vector<ll> x(N), y(M);
  for(int i=0;i<N;++i){
    cin>>x[i];
  }
  for(int i=0;i<M;++i){
    cin>>y[i];
  }
  ll tmpans = 0;
  for(int j=0;j<M-1;++j){
    tmpans += (y[j+1]-y[j])*(j+1)*(M-j-1);
    tmpans %= mod;
  }
  ll ans = 0;
  for(int i=0;i<N-1;++i){
    ans += (x[i+1]-x[i])*(i+1)%mod*(N-i-1)%mod*tmpans%mod;
    ans %= mod;
  }
  cout<<ans<<endl;
}

