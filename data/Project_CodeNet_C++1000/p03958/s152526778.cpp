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
  ll k,t,ans,s=0;cin>>k>>t;
  lvector A(t);rep(i,t) {cin>>A[i];s+=A[i];}
  sort(RALL(A));s-=A[0];
  if(t==1) ans=A[0]-1;
  else ans=max(0ll,A[0]-s-1);
  print(ans);
  return 0;
}
