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
  ll n,x,ans=0,s,m;cin>>n>>x;
  lvector A(n);rep(i,n) cin>>A[i];
  for(ll pos=1;pos<n;++pos) {
    s=A[pos-1]+A[pos];
    if(s<=x) continue;
    m=min(s-x,A[pos]);
    A[pos]-=m,ans+=m;
    s=A[pos-1]+A[pos];
    if(s>x) A[pos-1]-=s-x,ans+=s-x;
  }
  print(ans);
  return 0;
}