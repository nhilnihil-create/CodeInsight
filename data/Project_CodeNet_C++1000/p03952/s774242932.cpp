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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
long long N;


int main(){
  int n, x; cin >> n >> x;
  int ans[2*n-1] = {};
  if(n==2){
    if(x==1 || x==3){
      cout << "No" << endl; return 0;
    }
    cout << "Yes" << endl;
    rep(i, 3){
      cout << i+1 << endl;
    }
    return 0;
  }
  if(x==1 || x==(2*n-1)){
    cout << "No" << endl; return 0;
  }
  cout << "Yes" << endl;
  if(x==(2*n-2)){
    ans[n-1] = x; ans[n-2] = x-1; ans[n] = x+1; ans[n+1] = x-2;
    int ire = 1;
    rep(i, 2*n-1){
      if(ans[i]!=0) continue;
      ans[i] = ire; ire++;
    }
    rep(i, 2*n-1){
      cout << ans[i] << endl;
    }
    return 0;
  }
  ans[n] = x; ans[n-1] = x-1; ans[n-2] = x+1; ans[n+1] = x+2;
  int ire = 1;
  rep(i, 2*n-1){
    if(ire==x-1) ire+=4;
    if(ans[i]!=0) continue;
    ans[i] = ire; ire++;
  }
  rep(i, 2*n-1){
    cout << ans[i] << endl;
  }
}