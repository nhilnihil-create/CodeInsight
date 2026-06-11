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
  ll N, A, B, C, D; cin >> N >> A >> B >> C >> D; N--;
  ll K = (D*N - (B-A))/(D + C);
  if(D*N<(B-A)){
    cout << "NO" << endl; return 0;
  }
  ll dai = D*N - (D+C)*K;
  if((B-A) < dai - (D-C)*N) cout << "NO" << endl;
  else cout << "YES" << endl;
}