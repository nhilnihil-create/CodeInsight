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
  vector<ll> A(N);
  for(int i=0;i<N;++i) cin>>A[i];
  sort(A.begin(), A.end());
  int l=0, r=N-1, m;
  ll size;
  bool ok;
  while(l<r) {
    m = (l+r)/2;
    size = 0;
    for(int i=0;i<=m;++i) {
      size += A[i];
    }
    ok = true;
    for(int i=m+1;i<N;++i) {
      if(size*2<A[i]) {
        ok = false;
        break;
      }
      size += A[i];
    }
    if(ok) r = m;
    else l = m+1;
  }
  cout<<N-l<<endl;
}

