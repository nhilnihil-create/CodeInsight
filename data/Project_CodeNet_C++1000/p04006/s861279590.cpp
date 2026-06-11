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
const ll LINF = ll(1e18);
const ll MOD = ll(1e9+7);

int main(){
  int n, x;cin>>n>>x;
  vector<ll> a(n), mcost(n);
  rep(i, n){
    cin>>a[i];
    mcost[i]=a[i];
  }
  ll ans = LINF;
  rep(k, n){ // cast a spell k times
    ll cost = 0LL;
    rep(i, n){
      mcost[i] = min(mcost[i], a[(i+n-k)%n]);
      cost += mcost[i];
    }
    ans = min(ans, cost+ll(k)*x);
  }
  cout<<ans<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
