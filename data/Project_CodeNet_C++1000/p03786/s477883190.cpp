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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N;
  cin>>N;
  vector<ll> A(N), sumA(N);
  for(int i=0;i<N;++i) {
    cin>>A[i];
  }
  sort(A.begin(), A.end());
  for(int i=0;i<N;++i) sumA[i] = A[i];
  for(int i=1;i<N;++i) sumA[i] += sumA[i-1];
  int l=0, r=N, m;
  ll size;
  bool can;
  while(l<r) {
    m = (l+r)/2;
    size = sumA[m];
    can = true;
    for(int i=m+1;i<N;++i) {
      if(size*2>=A[i]) {
        size += A[i];
      }
      else can = false;
    }
    if(!can) l = m+1;
    else r = m;
  }
  cout<<N-l<<endl;
}

