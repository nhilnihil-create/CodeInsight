#include<iostream>
#include <cstring>
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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int main(){
  int N; ll L; cin >> N >> L; ll a[N];
  rep(i, N){
    cin >> a[i];
  }
  ll b[N-1]; ll ma = 0, mai;
  rep(i, N-1){
    b[i] = a[i]+a[i+1];
    if(ma<b[i]){
      ma=b[i];
      mai=i;
    }
  }
  if(ma<L){
    cout << "Impossible" << endl; return 0;
  }
  cout << "Possible" << endl;
  rep(i, mai){
    cout << i+1 << endl;
  }
  for(int i=N-2; i>=mai; i--){
    cout << i+1 << endl;
  }
}