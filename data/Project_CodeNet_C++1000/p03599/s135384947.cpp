#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
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
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

ll gcd(ll a, ll b) {
  ll v0=a, v1=b, v2=v0%v1;
  while(v2>0) {
    v0 = v1;
    v1 = v2;
    v2 = v0%v1;
  }
  return v1;
}

bool more(ll A, ll B, ll C, ll D) {
  ll yey = gcd(A, C);
  B *= C/yey;
  D *= A/yey;
  if(B<D) return true;
  else return false;
}

int main() {
  ll A, B, C, D, E, F;
  cin>>A>>B>>C>>D>>E>>F;
  ll ans1=1, ans2=0;
  ll t, s;
  for(ll i=0;i*100*A<=F;++i) {
    for(ll j=0;j*100*B<=F;++j) {
      t = 100*A*i+100*B*j;
      if(t==0) continue;
      if(t>F) continue;
      for(ll k=0;100*k*C<=E*t;++k) {
        for(ll l=0;100*l*D<=E*t;++l) {
          s = k*C+l*D;
          if(100*s>E*t) continue;
          if(t+s>F) continue;
          if(more(ans1, ans2, t, s)) {
            ans1 = t;
            ans2 = s;
          }
        }
      }
    }
  }
  if(ans1==1) cout<<100*A<<" "<<0<<endl;
  else cout<<ans1+ans2<<" "<<ans2<<endl;
}
