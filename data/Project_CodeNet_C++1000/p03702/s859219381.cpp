#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

vector<ll> h(mx);
ll n,a,b;
ll enemysum = 0;

bool finish(ll x){
  ll att = b*x;
  ll addi = a-b;
//  if(enemysum > addi*x + att*n) return false;
  ll cnt = 0;
  auto pos = upper_bound(h.begin(),h.end(), att);
  while(pos!=h.end()){
    int times = (*pos-att+addi-1)/addi;
    cnt += times*(h.end()-pos);

    att += times*addi;
    pos = upper_bound(h.begin(),h.end(), att);
    if(cnt>x) return false;
  }
  return cnt<=x;
}
 
int main(){
  cin >> n >> a >> b;
  h.resize(n);
  rep(i,n){ cin>>h[i]; enemysum += h[i]; }
  sort(h.begin(),h.end());
  ll l=0,r=inf,mid=(r+l)/2;
  while(r-l>1){
    mid=(r+l)/2;
    if(finish(mid)){ r=mid; }else{ l=mid; }
  }
  ll ans = r;
  cout << ans << endl;
  return 0;
}
