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
  int N, M;
  cin>>N>>M;
  int a[N], b[N], c[M], d[M];
  for(int i=0;i<N;++i) cin>>a[i]>>b[i];
  for(int i=0;i<M;++i) cin>>c[i]>>d[i];
  int tmp;
  int ans[N];
  for(int i=0;i<N;++i) {
    tmp = inf;
    for(int j=0;j<M;++j) {
      if(abs(a[i]-c[j])+abs(b[i]-d[j])<tmp) {
        tmp = abs(a[i]-c[j])+abs(b[i]-d[j]);
        ans[i] = j+1;
      }
    }
  }
  for(int i=0;i<N;++i) cout<<ans[i]<<endl;
}

