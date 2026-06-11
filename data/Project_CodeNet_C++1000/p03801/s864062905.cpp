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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n; cin >> n;
  vector<pair<ll,int>> a(n);
  rep(i,n){
    cin >> a[i].F;
    a[i].S = i;
  }
  sort(a.rbegin(),a.rend());
  vector<ll> b(n,0);
  int pos = n;
  rep(i,n-1){
    pos = min(pos,a[i].S);
    b[pos] += (i+1)*(a[i].F-a[i+1].F);
  }
  b[0] += n*a[n-1].F;
  for(auto ans:b){
    cout << ans << endl;
  }
  return 0;
}