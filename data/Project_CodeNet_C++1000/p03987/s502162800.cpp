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
#include<memory.h>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int n;
  cin >> n;
  ll a[n];
  ll ans=0;
  ll b[n];
  ll left=-1;
  ll right=n;
  rep(i,n){
    cin >> a[i];
    a[i]--;
    b[a[i]]=i;
  }
  set<ll> se;
  se.insert(-1);
  se.insert(n);
  rep(i,n){
    if(i>0){
      auto x=se.upper_bound(b[i]);
      right=*x;
      x--;
      left=*x;
    }
    se.insert(b[i]);
    ans+=(i+1)*((b[i]-left-1)*(right-b[i]-1)+right-left-1);
  }
  cout << ans << endl;
return 0;}
