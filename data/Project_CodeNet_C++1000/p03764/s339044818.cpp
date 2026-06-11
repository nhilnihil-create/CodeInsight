#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  ll N,M;
  cin>>N>>M;
  VL X(N),Y(M);
  rep(i,N) cin>>X[i];
  rep(i,M) cin>>Y[i];
  ll XX=0,YY=0;
  ll mod=1e9+7;
  rep(i,N-1) (XX+=(X[i+1]-X[i])*(i+1)%mod*(N-1-i)%mod)%=mod;
  rep(i,M-1) (YY+=(Y[i+1]-Y[i])*(i+1)%mod*(M-1-i)%mod)%=mod;
  cout<<XX*YY%mod<<endl;
}