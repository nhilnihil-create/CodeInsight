/*

*/
#include<iostream>
#include<iomanip>
#include<ios>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
#include<cstdlib>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)
#define MAX_N 10000

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;
const ll MOD = ll(1e9+7);

ll modinv(ll num){
  ll n=MOD-2LL;
  ll ret=1LL;
  while(n>0){
    if(n&1)ret=num*ret%MOD;
    num=num*num%MOD;
    n>>=1;
  }
  return ret;
}

int main(){
  ll h, w, a, b;cin>>h>>w>>a>>b;
  ll origin=1LL;
  repb(i, b+1, h-a+b){
    origin*=i;
    origin%=MOD;
  }
  repb(i, 1, h-a){
    origin*=modinv(ll(i));
    origin%=MOD;
  }
  repb(i, w-b, a+w-b-1){
    origin*=i;
    origin%=MOD;
  }
  repb(i, 1, a){
    origin*=modinv(ll(i));
    origin%=MOD;
  }
  ll ans=origin;
  repb(i, 1, w-b){
    origin*=h-a+b-1+i;
    origin%=MOD;
    origin*=modinv(ll(b+i));
    origin%=MOD;
    origin*=w-b-i;
    origin%=MOD;
    origin*=modinv(ll(a+w-b-1-i));
    origin%=MOD;
    ans+=origin;
    ans%=MOD;
  }
  cout<<ans<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
