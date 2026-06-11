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
#include <random>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  ll a[7];
  rep(i,7)cin >> a[i];
  ll ans=a[1];
  
  ans+=2*(a[0]/2)+2*(a[3]/2)+2*(a[4]/2);
  if(a[0]%2==1 && a[3]%2==1 && a[4]%2==1){
    ans+=3;
  }
  else if(a[0]>0 && a[0]%2==0 && a[3]%2==1 && a[4]%2==1){
    ans++;
  }
  else if(a[0]%2==1 && a[3]>0 && a[3]%2==0 && a[4]%2==1){
    ans++;
  }
  else if(a[0]%2==1 && a[4]>0 && a[4]%2==0 && a[3]%2==1){
    ans++;
  }
  cout << ans << endl;
return 0;}