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

ll op(lvector A,ll sign) {
  ll ret=0,S=0;
  for(ll a:A) {
    sign*=-1;
    S+=a;
    if(S*sign>0) continue;
    if(sign>0) ret+=(1-S),S=1;
    else ret+=(1+S),S=-1;
  }  
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  lvector A(n);rep(i,n) cin>>A[i];
  print(min(op(A,1),op(A,-1)));
  return 0;
}