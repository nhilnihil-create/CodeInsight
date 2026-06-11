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
  ll n,L;cin>>n>>L;
  lvector A(n);rep(i,n) cin>>A[i];
  ll x=-1;
  rep(i,n-1) if(A[i]+A[i+1]>=L) {x=i+1;break;}
  if(x==-1) print("Impossible");
  else {
    lvector ans;
    rep(i,x-1) ans.emplace_back(i+1);
    for(ll i=n-2;i>=x;--i) ans.emplace_back(i+1);
    ans.emplace_back(x);
    print("Possible");
    rep(i,n-1) print(ans[i]);
  }
  return 0;
}