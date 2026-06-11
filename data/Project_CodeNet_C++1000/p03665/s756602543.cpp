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

vector<lvector> comb(ll n) {
  vector<lvector> v(n+1,lvector(n+1,0));
  rep(i,n+1) {v[i][0]=1;v[i][i]=1;}
  for(ll j=1;j<n+1;++j)
  for(ll k=1;k<j;++k) v[j][k]=v[j-1][k-1]+v[j-1][k];
  return v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,res,zero=0,one=0;cin>>n>>res;
  lvector A(n);
  rep(i,n) {cin>>A[i];A[i]%=2;if(A[i]==0) zero++;else one++;}
  ll v=1,w=0;rep(i,zero) v*=2;
  vector<lvector> vec=comb(n);
  for(ll i=0;2*i+res<=one;++i) w+=vec[one][2*i+res];
  print(v*w);
  return 0;
}