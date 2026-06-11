#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
  int N, x;
  cin>>N>>x;
  if(x==1 || x==2*N-1){
    cout<<"No"<<endl;
    return 0;
  }
  vector<int> ans(2*N-1);
  for(int i=0;i<2*N-1;++i) ans[i] = 0;
  map<int, int> amap;
  ans[N-1] = x;
  ans[N-2] = x-1;
  ans[N] = x+1;
  amap[x-1]++;
  amap[x]++;
  amap[x+1]++;
  if(N>2){
    if(x+2<=2*N-1){
      ans[N-3] = x+2;
      amap[x+2]++;
    }
    if(x-2>0){
      ans[N+1] = x-2;
      amap[x-2]++;
    }
  }
  int index = 0;
  for(int i=1;i<=2*N-1;++i){
    if(amap[i]>0) continue;
    while(ans[index]!=0) index++;
    ans[index] = i;
  }
  cout<<"Yes"<<endl;
  for(int i=0;i<2*N-1;++i){
    cout<<ans[i]<<endl;
  }
}

