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
  int xmin=0, xmax=W, ymin=0, ymax=H;
  int x, y, a;
  for(int i=0;i<N;++i){
    cin>>x>>y>>a;
    if(a==1){
      if(xmin<x) xmin = x;
    }
    if(a==2){
      if(xmax>x) xmax = x;
    }
    if(a==3){
      if(ymin<y) ymin = y;
    }
    if(a==4){
      if(ymax>y) ymax = y;
    }
  }
  if(xmin>xmax || ymin>ymax) cout<<0<<endl;
  else cout<<(xmax-xmin)*(ymax-ymin)<<endl;
}

