#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;




int main(void) {
  ll N, M;
  cin >> N >> M;
  ll i;
  ll x[MAX], y[MAX];
  
  for(i=0; i<N; i++) cin >> x[i];
  for(i=0; i<M; i++) cin >> y[i];
  
  ll A=0, B=0;
  for(i=0; i<N; i++) moC(A, +, x[i]*(i-(N-1-i))%MOD);
  for(i=0; i<M; i++) moC(B, +, y[i]*(i-(M-1-i))%MOD);
  pt(A*B%MOD);
  
}



