#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <bitset>
#include <queue>

using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
#define rep(i, n) for(int i = 0;i < n;i++)
const long long INF = 1LL << 60;

int MOD = 1000000007;

int main(){
    std::ios_base::sync_with_stdio(false);
    // n, k
    int n,k; cin >> n >> k;
    std::vector<ll> a(n); rep(i,n) cin >> a[i];

    std::vector<ll> rskw(n); rskw[0]=a[0];
    for(int i=1; i<n; i++) rskw[i] = rskw[i-1]+a[i];

    std::vector<ll> best_rskw(n);

    if(a[0]<=0) best_rskw[0] = 0;
    else best_rskw[0] = a[0];

    for(int i=1; i<n; ++i){
      if(a[i] <= 0) best_rskw[i] = best_rskw[i-1];
      else best_rskw[i] = best_rskw[i-1]+a[i];
    }
    
    // rep(i,n) cout << rskw[i] << " ";
    // cout << '\n';
    // rep(i,n) cout << best_rskw[i] << " ";
    // cout << '\n';

    ll ans = 0LL;

    for(int i=0; i<n-k+1; i++){

      ll left = 0LL;
      ll right = 0LL;
      ll mid = rskw[i+k-1];

      if(i!=0) left = best_rskw[i-1];
      right = best_rskw[n-1]-best_rskw[i+k-1];

      if(i!=0) mid-=rskw[i-1];
      if(mid<0LL) mid=0LL;

      ans = max(ans, left+right+mid);
    }

    cout << ans << endl;
    
    return 0;
}
