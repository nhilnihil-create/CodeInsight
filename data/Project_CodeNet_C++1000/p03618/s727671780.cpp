#include <bits/stdc++.h>
#include <string>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) (a)=max(a, b);
#define chmin(a, b) (a)=min(a, b);
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
  
  string s;
  cin >> s;
  ll N=s.size();
  ll cnt[26]={};
  
  for(i=0; i<N; i++) cnt[s[i]-'a']++;
  
  ll ans=N*(N+1)/2;
  for(i=0; i<26; i++) ans-=cnt[i]*(cnt[i]+1)/2;
  
  ans++;
  pt(ans);
  
}



