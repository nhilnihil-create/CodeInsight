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

int a[maxn];
ll b[2 * maxn], c[2 * maxn];

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    ll sum = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1]) continue;
        if (a[i] < a[i + 1]) {
            sum += a[i + 1] - a[i];
            int l = a[i] + 1, r = a[i + 1];
            b[l] += a[i] + 1;
            b[r + 1] -= a[i] + 1;
            c[l] += 1;
            c[r + 1] -= 1;
        } else {
            sum += m - a[i];
            sum += a[i + 1];
            int l1 = a[i] + 1, r1 = m;
            int l2 = 1, r2 = a[i + 1];
            if (l1 <= r1) {
                b[l1] += a[i] + 1, b[r1 + 1] -= a[i] + 1;
                c[l1] += 1, c[r1 + 1] -= 1;
            }
            if (l2 <= r2) {
                b[l2] += a[i] + 1 - m, b[r2 + 1] -= a[i] + 1 - m;
                c[l2] += 1, c[r2 + 1] -= 1;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        b[i] += b[i - 1];
        c[i] += c[i - 1];
    }
    ll ans = LL_INF;
    for (int i = 1; i <= m; i++) {
        ll delta = (1LL * i * c[i] - b[i]);
        ans = min(ans, sum - delta);
    }
    printf("%lld\n", ans);

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
