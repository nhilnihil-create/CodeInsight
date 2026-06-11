#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MOD=1e9+7;
static const ll MAX=101010;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/



int main(void) {
  ll i, j, k, l;
  
  ll N;
  cin >> N;
  ll a[MAX];
  
  for(i=0; i<N; i++) cin >> a[i];
  
  
  ll ans=a[0]-1;
  ll h=2;
  for(i=1; i<N; i++) {
    if(a[i]==h) {
      h++;
    }else if(a[i]%h==0) {
      ans+=(a[i]-1)/h;
    }else {
      ans+=a[i]/h;
    }
  }
  
  pt(ans);
  
  
}


