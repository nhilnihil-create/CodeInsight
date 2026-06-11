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
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  ll N;
  cin>>N;
  VL A(N);
  rep(i,N) cin>>A[i];
  set<ll> S;
  S.insert(-1);
  S.insert(N);
  VL X(N);
  rep(i,N) X[A[i]-1]=i;
  ll ans=0;
  rep(i,N){
    auto itr=S.lb(X[i]);
    ll R=*itr;
    itr--;
    ll L=*itr;
    ans+=(R-X[i])*(X[i]-L)*(i+1);
    S.insert(X[i]);
  }
  cout<<ans<<endl;
}