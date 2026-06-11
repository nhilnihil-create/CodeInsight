#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
const int inf=1e9+7;
const ll longinf=1LL<<60;
const ll mod=1e9+7 ;

int main(){
  ll h,w;
  cin >> w >> h;
  ll p[w],q[h];
  rep(i,w)cin >> p[i];
  rep(i,h)cin >> q[i];
  sort(p,p+w);
  sort(q,q+h);
  ll sump[w]={},sumq[h]={};
  rep(i,w){
    sump[i]+=p[i];
    sump[i+1]=sump[i];
  }
  rep(i,h){
    sumq[i]+=q[i];
    sumq[i+1]=sumq[i];
  }
  ll ans=longinf;
  ll temp=sump[w-1]+sumq[h-1];
  rep(i,w){
    int x=upper_bound(q,q+h,p[i])-q;
    if(x>=1)temp+=sumq[x-1];
    temp+=(h-x)*p[i];
  }
  ans=min(ans,temp);
  cout << ans << endl;
return 0;}