/*
    Written by Nitrogens
    Desire for getting accepted!!
*/
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 1e5+5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl

int n;
ll a, b;
ll h[maxn];

ll divv(ll x, ll y) {
    if (x % y == 0) return x / y;
    else return x / y + 1;
}

bool check(ll x) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (divv(h[i], b) <= x) continue;
        ll delta = h[i] - x * b;
        ll cnt2 = divv(delta, a - b);
        cnt += cnt2;
    }
    return cnt <= x;
}

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);

    scanf("%d%lld%lld", &n, &a, &b);
    for (int i = 1; i <= n; i++) scanf("%lld", &h[i]);
    ll ans = LL_INF;
    ll left = 0, right = LL_INF;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (check(mid)) {
            ans = min(ans, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    printf("%lld\n", ans);

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
