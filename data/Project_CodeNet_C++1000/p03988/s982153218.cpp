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
  map<int, int> amap;
  int A[N];
  int maxnum = 0, minnum = inf;
  for(int i=0;i<N;++i) {
    cin>>A[i];
    maxnum = max(maxnum, A[i]);
    minnum = min(minnum, A[i]);
    amap[A[i]]++;
  }
  bool can;
  if(minnum==(maxnum+1)/2) can = true;
  else can = false;
  if(!can) {
    cout<<"Impossible"<<endl;
    return 0;
  }
  for(int i=minnum;i<=maxnum;++i) {
    if(i==minnum) {
      if(maxnum%2==0) {
        if(amap[i]!=1) can = false;
      }
      else {
        if(amap[i]!=2) can = false;
      }
    }
    else if(i==maxnum) {
      if(amap[i]<2) can = false;
    }
    else {
      if(amap[i]<2) can = false;
    }
  }
  if(can) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}

