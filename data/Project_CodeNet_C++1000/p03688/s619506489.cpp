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

int main(){
  ll n;
  cin >> n;
  ll a[n];
  rep(i,n)cin >> a[i];
  sort(a,a+n);
  if(a[n-1]-a[0]>1){
    cout << "No" << endl;
    return 0;
  }
  if(a[n-1]==a[0]){
    if(n>=2*a[0] || a[0]==n-1){
      cout << "Yes" << endl;
    }else cout << "No" << endl;
    return 0;
  }
  ll mincnt=0;
  rep(i,n){
    if(a[i]==a[0])mincnt++;
  }
  n-=mincnt;
  if((a[0]+1-mincnt>0 && n>=2*(a[0]+1-mincnt)) || (a[0]+1-mincnt==1 && n>1)){
    cout << "Yes" << endl;
  }else cout << "No" << endl;
return 0;}