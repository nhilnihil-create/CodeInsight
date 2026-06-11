#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(ll i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int w,h,n;
  cin >> w >> h >> n;
  int x0=0, x1=w, y0=0, y1=h;
  rep(i,n){
    int x,y,a;
    cin >> x >> y >> a;
    if(a==1){
      x0 = max(x0, x);
    } else if(a==2){
      x1 = min(x1, x);
    } else if(a==3){
      y0 = max(y0, y);
    } else if(a==4){
      y1 = min(y1, y);
    }
  }
  int X = max(0,(x1-x0));
  int Y = max(0,(y1-y0));
  int ans = X*Y;
  cout << ans << ln;
  return 0;
}