#include <bits/stdc++.h>
#include <string>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) (a)=max(a, b)
#define chmin(a, b) (a)=min(a, b)
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;


/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/


int main(void) {
  ll i, j, k;
  
  ll N;
  cin >> N;
  ll a[MAX];
  ll cnt[MAX]={};
  
  for(i=0; i<N; i++) cin >> a[i];
  sort(a, a+N);
  reverse(a, a+N);
  
  ll f=0;
  if(a[0]>a[1]) {pt("Impossible"); return 0;}
  if(a[N-1]!=(a[0]+1)/2) {pt("Impossible"); return 0;}
  
  
  for(i=0; i<N; i++) cnt[a[i]]++;
  
  for(i=a[N-1]+1; i<=a[0]; i++)
    if(cnt[i]<=1) {pt("Impossible"); return 0;}
  
  if(cnt[a[N-1]]>2) {pt("Impossible"); return 0;}
  
  if(a[0]&1 && cnt[a[N-1]]==1) {pt("Impossible"); return 0;}
  if(!(a[0]&1) && cnt[a[N-1]]==2) {pt("Impossible"); return 0;}
  
  pt("Possible");
}



