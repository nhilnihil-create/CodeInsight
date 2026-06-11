#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  ll T[N], A[N];
  for(int i=0;i<N;++i) cin>>T[i];
  for(int i=0;i<N;++i) cin>>A[i];
  if(T[N-1]!=A[0]) {
    cout<<0<<endl;
    return 0;
  }
  ll mh = T[N-1];
  int l=-1, r=-1;
  for(int i=0;i<N;++i) {
    if(T[i]==mh && A[i]==mh) {
      l = i;
      break;
    }
  }
  for(int i=N-1;i>=0;--i) {
    if(T[i]==mh && A[i]==mh) {
      r = i;
      break;
    }
  }
  if(l==-1) {
    cout<<0<<endl;
    return 0;
  }
  ll ans = 1;
  for(int i=1;i<l;++i) {
    if(T[i]==T[i-1]) {
      ans *= T[i];
      ans %= mod;
    }
  }
  for(int i=N-2;i>=r;--i) {
    if(A[i]==A[i+1]) {
      ans *= A[i];
      ans %= mod;
    }
  }
  for(int i=0;i<r-l-1;++i) {
    ans *= mh;
    ans %= mod;
  }
  cout<<ans<<endl;
}

