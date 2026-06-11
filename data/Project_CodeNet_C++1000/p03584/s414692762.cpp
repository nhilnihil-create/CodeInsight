#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <functional>
#include <set>
#define DB cerr<<"D"<<endl
#define pb push_back
using namespace std; using ll=long long; using ld=long double; const int INF=1e9; const ll LINF=1e18; const double dINF = 1e18; const ld ldINF = 1e18; const double EPS = 1e-6;
template<typename T, typename U, typename O> void caut(T a, U b, O c){cout<<"("<<a<<","<<b<<","<<c<<") ";} template<typename T, typename U> void caut(T a, U b){cout<<"("<<a<<","<<b<<") ";} template<typename T> void caut(T a){cout<<"("<<a<<") ";}
using P=pair<double,int>;
const ll M = 1e9+7;
void add(ll& x, ll y) {x+=y; x%=M;}
void chmax(ll& x, ll y) {if (x<y) x=y;}
ll mod_pow(ll x, ll a) { ll an = 1; while(a > 0) { if (a&1) an = an * x % M; x = x * x % M; a >>= 1;} return an;}

int main() {
  ll n; cin>>n;
  ll k; cin>>k;
  ll a[n],b[n];
  for(int i=0;i<n;i++) cin>>a[i]>>b[i];

  ll an=0,sm=0;
  for(int i=0;i<n;i++) {
    if ((k | a[i]) == k) {
      sm+=b[i];
    }
  }
  an=max(an,sm);

  for(ll i=2;i<=k;i<<=1) {
    if ((k & i) == 0) continue;
    ll k2 = k;
    k2 ^= i; k2 |= i-1;
    sm = 0;
    for(int j=0;j<n;j++) {
      if ((k2 | a[j]) == k2) {
        sm += b[j];
      }
    }
    an = max(an,sm);
  }
  cout<<an<<endl;
}