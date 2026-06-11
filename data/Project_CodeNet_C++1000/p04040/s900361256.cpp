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
#define pint pair<int,int>
#define pll pair<ll,ll>
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

const int MAX = 510000;
const int MOD = 1e9+7;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  COMinit();
  ll h,w,a,b;
  cin >> h >> w >> a >> b;
  ll ans=1;
  ans*=COM(h-a-1+b,b);
  ans%=mod;
  ans*=COM(w+a-2-b,a-1);
  ans%=mod;
  for(int i=b+2;i<=w;i++){
    ll temp=1;
    temp*=COM(i-1+h-a-1,i-1);
    temp%=mod;
    temp*=COM(w-i+a-1,a-1);
    temp%=mod;
    ans+=temp;
    ans%=mod;
  }
  cout << ans << endl;
return 0;}