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

int main(){
  ll n, a, b;cin>>n>>a>>b;
  a-=b;
  vector<ll> h(n);
  rep(i, n)cin>>h[i];
  ll l=0LL, r=ll(1e9)+1LL;
  while(l+1LL!=r){
    ll m=(l+r)/2;
    ll cnt=0LL;
    rep(i, n){
      ll rest=h[i]-b*m;
      if(rest>0LL){
        cnt+=(rest+a-1LL)/a;
      }
    }
    if(cnt<=m){
      // printf("[%lld, %lld) (mid=%lld): ok\n", l, r, m);
      r=m;
    }else{
      // printf("[%lld, %lld) (mid=%lld): not ok\n", l, r, m);
      l=m;
    }
  }
  cout<<r<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
