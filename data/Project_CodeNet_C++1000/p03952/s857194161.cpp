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
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, x;
  cin>>N>>x;
  int ans[2*N-1];
  for(int i=0;i<2*N-1;++i) ans[i] = 0;
  map<int, int> amap;
  if(N==2 && x==2) {
    cout<<"Yes"<<endl;
    cout<<1<<endl;
    cout<<2<<endl;
    cout<<3<<endl;
    return 0;
  }
  if(1<=x-1 && x+2<=2*N-1) {
    ans[N-2] = x+1;
    amap[x+1]++;
    ans[N-1] = x-1;
    amap[x-1]++;
    ans[N] = x;
    amap[x]++;
    ans[N+1] = x+2;
    amap[x+2]++;
    int now = 1;
    for(int i=0;i<2*N-1;++i) {
      if(ans[i]>0) continue;
      while(amap[now]>0) now++;
      ans[i] = now;
      amap[now]++;
    }
    cout<<"Yes"<<endl;
    for(int i=0;i<2*N-1;++i) cout<<ans[i]<<endl;
    return 0;
  }
  if(1<=x-2 && x+1<=2*N-1) {
    ans[N-2] = x-2;
    amap[x-2]++;
    ans[N-1] = x;
    amap[x]++;
    ans[N] = x+1;
    amap[x+1]++;
    ans[N+1] = x-1;
    amap[x-1]++;
    int now = 1;
    for(int i=0;i<2*N-1;++i) {
      if(ans[i]>0) continue;
      while(amap[now]>0) now++;
      ans[i] = now;
      amap[now]++;
    }
    cout<<"Yes"<<endl;
    for(int i=0;i<2*N-1;++i) cout<<ans[i]<<endl;
    return 0;
  }
  cout<<"No"<<endl;
}

