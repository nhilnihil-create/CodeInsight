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
  int W,H;
  cin>>W>>H;
  VL P(W),Q(H);
  rep(i,W) cin>>P[i];
  rep(i,H) cin>>Q[i];
  vector<PLL> R(0);
  rep(i,W) R.pb(mp(P[i],0));
  rep(i,H) R.pb(mp(Q[i],1));
  sort(all(R));
  ll ans=0;
  rep(i,R.size()){
    if(R[i].second==0){
      ans+=(H+1)*R[i].first;
      W--;
    }else{
      ans+=(W+1)*R[i].first;
      H--;
    }
  }
  cout<<ans<<endl;
}