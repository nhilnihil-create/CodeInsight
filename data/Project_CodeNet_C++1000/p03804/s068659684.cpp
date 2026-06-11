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
  ll n,m;cin>>n>>m;
  string s;
  svector A(n),B(m);
  rep(i,n) cin>>A[i];rep(i,m) cin>>B[i];
  bool isok=false,tmp;
  for(ll a=0;a<n;++a) {
    for(ll apos=0;apos+m<=n;apos++) {
      if(B[0]==A[a].substr(apos,m)) {
        tmp=true;
        for(ll bpos=1;bpos<m;++bpos) {
          if(a+bpos<n&&B[bpos]==A[a+bpos].substr(apos,m)) continue;
          tmp=false;
        }
        isok=tmp;
      }
      if(isok) break;
    }
    if(isok) break;
  }
  print(isok?"Yes":"No");
  return 0;
}