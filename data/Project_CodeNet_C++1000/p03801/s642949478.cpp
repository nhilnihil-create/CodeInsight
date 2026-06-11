#include <bits/stdc++.h>
#include <string>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PL;
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
  
  for(i=0; i<N; i++) cin >> a[i];
  
  ll cnt[MAX]={};
  map<ll, ll, greater<>> mp;
  map<ll, ll> cp;
  for(i=N-1; i>=0; i--) {
    mp[a[i]]=i;
    cp[a[i]]++;
  }
  mp[0]=-1;
  
  ll t=0;
  ll p=N-1;
  for(auto it=mp.begin(); it!=mp.end(); it++) {
    if(it->first==0) continue;
    
    auto nt=it; nt++;
    ll A=it->first, B=nt->first;
    t+=cp[A];
    chmin(p, mp[A]); //mp[A]:it->second
    
    cnt[p]+=t*(A-B);
  }
  
  for(i=0; i<N; i++) pt(cnt[i]);
}

