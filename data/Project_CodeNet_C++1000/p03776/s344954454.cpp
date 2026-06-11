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

ll mem[111][111];

ll C(ll n, ll k) {
  if(n<k||n<0||k<0) return 0;
  if(k==0) return 1;
  if(n==k) return 1;
  if(mem[n][k]!=-1) return mem[n][k];
  return mem[n][k]=C(n-1, k)+C(n-1, k-1);
}


int main(void) {
  ll i, j, k, l;
  
  memset(mem, -1, sizeof(mem));
  
  ll N, A, B;
  cin >> N >> A >> B;
  ll v[55];
  
  for(i=0; i<N; i++) cin >> v[i];
  sort(v, v+N);
  reverse(v, v+N);
  
  ll ans=0;
  ll s=0, t=0;
  for(i=0; v[i]!=v[A-1]; ans+=v[i], i++, s++);
  for(i=0; i<N; i++) if(v[i]==v[A-1]) t++;
  
  ans+=v[A-1]*(A-s);
  printf("%.10f\n", (double)ans/A);
  
  if(s) {
    pt(C(t, A-s));
  }else {
    ll c=0;
    for(i=A; i<=min(B, t); i++) c+=C(t, i);
    pt(c);
  }
  
  
  
}


