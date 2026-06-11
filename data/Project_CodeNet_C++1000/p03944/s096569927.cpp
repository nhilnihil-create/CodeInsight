#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <set>
#include <map>
#include <stdio.h>
#include <numeric>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define MOD 1000000007 //10^9+7
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int INF = numeric_limits<int>::max();
const ll INFL = numeric_limits<ll>::max();


// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

//greatest common divisor
long long gcd(ll a, ll b) 
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

//least common multiple
long long lcm(ll a, ll b)
{
    return a / gcd(a, b) * b ;
}

ll factorial(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

bool is_prime(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

int main()
{
    int w, h, n; cin >> w >> h >> n;
    int a[h][w];
    memset(a, 0, sizeof(a));
    rep(i,n) {
        int x, y, aa; cin >> x >> y >> aa;
        x--; y--;
        if (aa == 1) {
            rep(i,h) {
                rep(j,x+1) {
                    a[i][j] = 1;
                }
            }
        } else if (aa == 2) {
            rep(i,h) {
                for (int j = x+1; j < w; j++) {
                    a[i][j] = 1;
                }
            }
        } else if (aa == 3) {
            rep(i,y+1) {
                rep(j,w) {
                    a[i][j] = 1;
                }
            }
        } else {
            for (int i = y+1; i < h; i++) {
                rep(j,w) {
                    a[i][j] = 1;
                }
            }
        }
    }

    int ans = 0;
    rep(i,h) {
        rep(j,w) {
            if (!a[i][j])
                ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
