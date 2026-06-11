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
using P=pair<ll,ll>;
const ll M = 1e9+7;
void add(ll& x, ll y) {x+=y; x%=M;}
void chmax(ll& x, ll y) {if (x<y) x=y;}

int main() {
  ll k,t; cin>>k>>t;
  ll mx=0;
  ll a[t]; for(int i=0;i<t;i++) cin>>a[i];
  for(int i=0;i<t;i++) mx=max(mx,a[i]);
  if (mx <= k/2+k%2) cout<<0<<endl;
  else {
    if (k%2==1) {
      cout<<(mx-(k/2+k%2))*2<<endl;
    } else {
      cout<<(mx-(k/2+k%2))*2-1<<endl;
    }
  }
}