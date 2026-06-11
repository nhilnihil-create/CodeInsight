#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a,b,c,d,e,f,sugar=0,mass=0;
  cin>>a>>b>>c>>d>>e>>f;
  lvector S,W;
  for(ll a_=0;100*a*a_<=f;++a_) {
    for(ll b_=0;100*b*b_<=f;++b_) {
      if(100*a*a_+100*b*b_<=f) W.emplace_back(100*a*a_+100*b*b_);
    }
  }
  for(ll c_=0;c*c_<=3000;++c_) {
    for(ll d_=0;d*d_<=3000;++d_) {
      if(c*c_+d*d_<=3000) S.emplace_back(c*c_+d*d_);
    }
  }
  double max_c=-1.0,c_tmp;
  for(ll w:W) {
    if(w==0) continue;
    for(ll s:S) {
      if(!(s+w<=f&&e*w>=s*100)) continue;
      c_tmp=100.0*s/(w+s);
      if(max_c<c_tmp) {
        max_c=c_tmp;
        sugar=s;
        mass=s+w;
      }
    }
  }
  printf("%lld %lld\n",mass,sugar);
  return 0;
}