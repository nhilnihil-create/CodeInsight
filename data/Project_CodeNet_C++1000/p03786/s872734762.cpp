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
  ll n,v=0;cin>>n;
  lvector A(n),S(n,0);rep(i,n) cin>>A[i];
  sort(ALL(A));
  S[0]+=A[0];rep(i,n-1) S[i+1]=S[i]+A[i+1];
  rep(i,n-1) if(2*S[i]<A[i+1]) v=i+1;
  print(n-v);
  return 0;
}