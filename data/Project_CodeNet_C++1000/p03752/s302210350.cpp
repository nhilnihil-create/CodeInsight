#include <bits/stdc++.h>
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
#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/

const int mx=200010;
const ll mod=1e9+7;

int main(){  
  int n,k;
  cin >> n >> k;
  vector<ll> data(n);
  rep(i,n){ cin >> data[i]; }
  
  int m = (1<<n);
  ll ans=longinf;
  rep(b,m)if(__builtin_popcount(b) == k && bit(b,0)){
    ll tmp=0;
    ll cnt=0;
    auto a=data;
    int pre=-1;
    rep(i,n){
      if(bit(b,i)){
        if(pre!=-1){
          tmp += (cnt>a[pre]?cnt-a[pre]:0);
        }
        tmp += (cnt>=a[i]?cnt-a[i]+1:0);
        cnt = max(cnt+1, a[i]);
        a[i] = cnt;
        pre = i;
      }
      cnt = max(cnt, a[i]);
    }

    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}