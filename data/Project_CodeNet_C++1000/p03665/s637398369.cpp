#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std; using ll=long long; using ld=long double; using P=pair<ll,ll>; const int INF=1e9; const ll LINF=1e18;
ll pou(ll x, ll a) { ll an = 1; while(a > 0) { if (a&1) an = an * x; x = x * x; a >>= 1;} return an;}
ll gcd(ll a, ll b) {if (b==0) return a; else return gcd(b, a%b);}
const ll m = 1e9+7; vector<ll> sm(200005), inv(200005);
ll mod_pow(ll x, ll a) { ll an = 1; while(a > 0) { if (a&1) an = an * x % m; x = x * x % m; a >>= 1;} return an;}
void sm_build() {
	sm[0]=1;for(ll i=1;i<200005;i++) sm[i]=sm[i-1]*i%m;
	inv[200004]=mod_pow(sm[200004],m-2);for(ll i=200003;i>=0;i--) inv[i]=inv[i+1]*(i+1)%m;
}
ll ncr(ll n, ll r) {return sm[n] * inv[n-r] % m * inv[r] % m;}
ll ncr2(ll n, ll r) {return sm[n] * mod_pow(sm[n-r], m-2) % m * mod_pow(sm[r], m-2) % m;}

int main(){
  sm_build();
  int n,p; cin>>n>>p;
  int f[2]={0,0};
  for(int i=0;i<n;i++) {
    int a; cin>>a; f[a%2]++;
  }
  ll an=0;
  for(int i=p;i<=f[1];i+=2) {
    an+=ncr(f[1],i)*pou(2,f[0]);
  }
  cout<<an<<endl;
}