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
  ll i, j;
  ll x[MAX];
  vector<ll> v[MAX];
  for(i=0; i<N; i++) {
    cin >> x[i];
    v[x[i]%M].push_back(x[i]);
  }
  
  for(i=0; i<M; i++) {
    v[i].push_back(INF);
    sort(v[i].begin(), v[i].end());
  }
  
  vector<ll> cnt[MAX];
  for(i=0; i<M; i++) {
    for(j=0; j<v[i].size(); j++) {
      ll t=1;
      while(v[i][j]==v[i][j+1]) {
        t++;
        j++;
      }
      cnt[i].push_back(t);
    }
    sort(cnt[i].begin(), cnt[i].end());
  }
  
  //INFの分を取り除く
  for(i=0; i<M; i++) cnt[i].erase(cnt[i].begin());
  
  ll s[MAX]={};
  ll odd[MAX]={};
  for(i=0; i<M; i++) {
    ll t=0;
    for(j=0; j<cnt[i].size(); j++) {
      t+=cnt[i][j];
      if(cnt[i][j]&1) odd[i]++;
    }
    s[i]=t;
  }
  
  ll ans=s[0]/2;
  if(M%2==0) ans+=s[M/2]/2;
  
  for(i=1; i<=M/2-(M&1 ? 0:1); i++) {
    ll a=i;
    ll b=M-i;
    
    if(s[a]>s[b]) swap(a, b);
    
    if(s[a]>=odd[b]) {
      ans+=s[a]+(s[b]-s[a])/2;
    }else {
      ans+=s[a]+(s[b]-odd[b])/2;
    }
    
  }
  
  pt(ans);
}






