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
  int W, H, N;
  cin>>W>>H>>N;
  int x, y, a;
  int maxx=W, minx=0, maxy=H, miny=0;
  for(int i=0;i<N;++i){
    cin>>x>>y>>a;
    if(a==1){
      minx = max(minx, x);
    }
    if(a==2){
      maxx = min(maxx, x);
    }
    if(a==3){
      miny = max(miny, y);
    }
    if(a==4){
      maxy = min(maxy, y);
    }
  }
  if(maxx<=minx || maxy<=miny) cout<<0<<endl;
  else cout<<max(0, (maxx-minx)*(maxy-miny))<<endl;
}

