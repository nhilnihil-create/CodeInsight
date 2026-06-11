#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m;cin>>n>>m;
  vector<lvector> A(n,lvector(m,0));
  rep(i,n)rep(j,m) {cin>>A[i][j];}
  ll ans=1e9,maxnum=0,maxpos=0;
  lvector v(m+1,0);
  while(A[0].size()) {
    rep(i,n) v[A[i][0]]++;
    maxpos=max_element(ALL(v))-v.begin();
    maxnum=v[maxpos];
    ans=min(ans,maxnum);
    rep(i,m+1) v[i]=0;
    for(ll i=0;i<n;++i) A[i].erase(find(ALL(A[i]),maxpos));
  }
  print(ans);
  return 0;
}