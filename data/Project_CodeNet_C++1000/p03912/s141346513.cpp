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
  int N, M;
  cin>>N>>M;
  int X[N];
  for(int i=0;i<N;++i) cin>>X[i];
  map<int, int> amap, bmap;
  for(int i=0;i<N;++i) {
    amap[X[i]%M]++;
    bmap[X[i]]++;
  }
  map<int, int> cmap;
  for(int i=1;i<=100000;++i) {
    cmap[i%M] += bmap[i]/2;
  }
  int ans = 0;
  ans += amap[0]/2;
  if(M%2==0) {
    for(int i=1;i<M/2;++i) {
      if(amap[i]>amap[M-i]){
        ans += amap[M-i];
        amap[i] -= amap[M-i];
        amap[M-i] = 0;
        ans += min(amap[i]/2, cmap[i]);
      }
      else {
        ans += amap[i];
        amap[M-i] -= amap[i];
        amap[i] = 0;
        ans += min(amap[M-i]/2, cmap[M-i]);
      }
    }
    ans += amap[M/2]/2;
  }
  else {
    for(int i=1;i<=M/2;++i) {
      if(amap[i]>amap[M-i]){
        ans += amap[M-i];
        amap[i] -= amap[M-i];
        amap[M-i] = 0;
        ans += min(amap[i]/2, cmap[i]);
      }
      else {
        ans += amap[i];
        amap[M-i] -= amap[i];
        amap[i] = 0;
        ans += min(amap[M-i]/2, cmap[M-i]);
      }
    }
  }
  cout<<ans<<endl;
}

