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
const ll mod=998244353 ;

        
    
int main(){
  int n, m; cin >> n >> m;  ll a[n]; ll sum = 0;
  rep(i, n){
    cin >> a[i]; a[i]--;
  }
  ll ans[2*m] = {}; ll ato[n-1] = {};
  rep(i, n-1){
    if(a[i+1]-a[i]==1){
      sum++; continue;
    }
    ans[(a[i]+2)]++;
    ato[i] = a[i+1]+1;
    if(a[i+1]<a[i]) ato[i]+=m;
    ans[ato[i]]--;
    sum+=(a[i+1]-a[i]+m)%m;
    //cout << sum << endl;
  }
  //rep(i, 2*m){
    //cout << ans[i] << " ";
  //}
  //cout << endl;
  rep(i, 2*m-1){
    ans[i+1]+=ans[i];
  }
  //rep(i, 2*m){
    //cout << ans[i] << " ";
  //}
  //cout << endl;//単純imos完了！
  rep(i, n-1){
    ans[ato[i]]-=(a[i+1]-a[i]-1+m)%m;
    //cout << (a[i+1]-a[i]-1+m)%m << endl;
  }
  //rep(i, 2*m){
    //cout << ans[i] << " ";
  //}
  //cout << endl;
  rep(i, 2*m-1){
    ans[i+1]+=ans[i];
  }
   //rep(i, 2*m){
    //cout << ans[i] << " ";
  //}//あとは合わせるだけの段階
  //cout << endl;
  rep(i, m){
    ans[i]+=ans[i+m];
  }
  ll tmp = -longinf;
  rep(i, m){
    tmp = max(tmp, ans[i]);
  }
  cout << sum-tmp << endl;
}