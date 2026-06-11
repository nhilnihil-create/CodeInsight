#include<iostream>
#include<string>
#include<cstring>
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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;
#define PI 3.141592653589793

int main(){
  int N; cin >> N;
  pair<ll, ll>P = {1, 1};
  rep(i, N){
    ll a, b; cin >> a >> b;
    ll p = max((P.first-1)/a + 1, (P.second-1)/b + 1);
    P.first=a*p; P.second=b*p;
    //cout << P.first << " " << P.second << endl;
  }
  cout << P.first+P.second << endl;
}