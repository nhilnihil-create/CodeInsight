#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <functional>
#include <bitset>
#define DB cerr<<"D"<<endl
#define pb push_back
using namespace std; using ll=long long; using ld=long double; const int INF=1e9; const ll LINF=1e18; const double dINF = 1e18; const ld ldINF = 1e18; const double EPS = 1e-6;
template<typename T, typename U, typename O> void caut(T a, U b, O c){cout<<"("<<a<<","<<b<<","<<c<<") ";}
template<typename T, typename U> void caut(T a, U b){cout<<"("<<a<<","<<b<<") ";}
template<typename T> void caut(T a){cout<<"("<<a<<") ";}
using P=pair<double,int>;
const ll M = 1e9+7;

int main() {
  int n; cin>>n;
  int p[n];for(int i=0;i<n;i++) cin>>p[i];

  ll ka[n]={}, kb[n+1]={}, aa[n]={}, ab[n]={};
  for(int i=0;i<n;i++) {
    ka[i]=kb[i]=1;
  }

  for(int i=0;i<n;i++) {
    if (i==0) continue;
    ka[p[i]-1]+=i;
    kb[p[i]]+=i;
  }

  ll nw=0;
  for(int i=0;i<n;i++) {
    nw+=ka[i]; aa[i]=nw;
  }
  nw=1e9;
  for(int i=0;i<n;i++) {
    nw-=kb[i]; ab[i]=nw;
  }
  for(int i=0;i<n;i++) {
    cout<<aa[i]<<" ";
  } cout<<endl;
  for(int j=0;j<n;j++) {
    cout<<ab[j]<<" ";
  } cout<<endl;
}
// Thank you for making problems and running the contest