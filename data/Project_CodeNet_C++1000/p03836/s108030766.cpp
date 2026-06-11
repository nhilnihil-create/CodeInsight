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
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int x = c-a;
  int y = d-b;
  rep(i,x){ cout << 'R'; }
  rep(i,y){ cout << 'U'; }
  rep(i,x){ cout << 'L'; }
  rep(i,y){ cout << 'D'; }
  cout << 'D';
  rep(i,x+1){ cout << 'R'; }
  rep(i,y+1){ cout << 'U'; }
  cout << 'L';
  cout << 'U';
  rep(i,x+1){ cout << 'L'; }
  rep(i,y+1){ cout << 'D'; }
  cout << 'R';
  cout << ln;
  return 0;
}