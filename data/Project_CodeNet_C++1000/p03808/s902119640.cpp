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


/*
 * 3 -> 1 -> 3 
 *
 * 2 3 1 | -1 2 -1 | 0 3 0
 * 3 5 4 | -2 1  1 | 0 3 3
 * 5 8 5 | -3 3  0 | 0 6 3
 */

int main(){
    std::ios_base::sync_with_stdio(false);
    int n; cin >> n;
    std::vector<int> a(n);
    rep(i,n) cin >> a[i];

    ll s=0; rep(i,n) s+=a[i];
    ll k=0; rep(i,n) k+=i+1LL;

    if(s%(k+0LL) != 0LL){cout << "NO" << '\n'; return 0;}
    ll d=s/k;

    std::vector<int> diff(n);
    rep(i,n-1) diff[i]=a[i]-a[i+1];
    diff[n-1] = a[n-1]-a[0];

    // rep(i,n) cout << diff[i] << " ";
    // cout << '\n';

    rep(i,n) diff[i]+=d;

    // rep(i,n) cout << diff[i] << " ";
    // cout << '\n';

    rep(i,n){
        if(diff[i]%n!=0 || diff[i]<0){cout << "NO" << '\n'; return 0;}
        diff[i]/=n;
    }

    cout << "YES" << endl;
    
    return 0;
}
