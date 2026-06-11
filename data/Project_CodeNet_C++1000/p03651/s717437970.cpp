#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

ll gcd ( ll a, ll b ) {
    if ( b > a ) swap(a, b);
    if ( a % b == 0 ) return b;
    return gcd ( b, a % b );
}

int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    if ( a[n-1] < k ) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    ll gcd_num = a[0];
    for ( int i = 1; i < n; ++i ) {
        gcd_num = gcd(a[i], gcd_num);
    }
    if ( k % gcd_num == 0 ) {
        cout << "POSSIBLE" << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
