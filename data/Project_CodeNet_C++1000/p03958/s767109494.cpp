#include <bits/stdc++.h>
#include <string>
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

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/



int main(void) {
  ll i, j, k;
  
  ll K, N;
  cin >> K >> N;
  ll a[111];
  ll s=0;
  
  for(i=0; i<N; i++) cin >> a[i];
  sort(a, a+N);
  for(i=0; i<N-1; i++) s+=a[i];
  
  pt(max(0LL, a[N-1]-s-1));
  
}

