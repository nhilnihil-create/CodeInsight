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
  int n; cin>>n;
  ll a[n],b[n];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>b[i];

  bool p[n]={};
  ll nw = -1;
  for(int i=0;i<n;i++) {
    if (nw != a[i]) {
      if (a[i] > b[i]) {
        cout<<"0"<<endl;
        return 0;
      }
      p[i]=true;
      nw = a[i];
    }
  }

  nw = -1;
  for(int i=n-1;i>=0;i--) {
    if (nw != b[i]) {
      if (a[i] < b[i]) {
        cout<<"0"<<endl;
        return 0;
      }
      p[i]=true;
      nw = b[i];
    }
  }

  ll an=1;
  for(int i=0;i<n;i++) {
    if (p[i]) continue;
    an*=min(a[i],b[i]); an%=M;
  }
  cout<<an<<endl;
}