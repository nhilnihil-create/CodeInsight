#include "bits/stdc++.h"
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (int)(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 4e18;

//平行四辺形:タテaヨコb
ll leng(ll a, ll b) {
    ll ans = 0;
    if (a < b) swap(a, b);
    ans += a / b * 2 * b;
    if (a % b != 0) {
        ans += leng(a%b, b);
    }
    else {
        ans -= b;
    }
    return ans;
}

int main() {
    ll n, x; cin >> n >> x;
    ll r = n;
    cout << leng(n-x,x)+n << endl;
    getchar(); getchar();
}