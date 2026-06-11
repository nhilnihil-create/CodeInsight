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
#include <unordered_map>
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
map<ll, ll> sum, cnt;

ll lowbit(ll x) {return x & (-x);}

void update(ll pos, ll val) {
    while (pos <= 1000000000LL) {
        sum[pos] += val;
        cnt[pos] += 1;
        pos += lowbit(pos);
    }
}

ll query_sum(ll pos) {
    ll res = 0;
    while (pos > 0) {
        res += sum[pos];
        pos -= lowbit(pos);
    }
    return res;
}

ll query_cnt(ll pos) {
    ll res = 0;
    while (pos > 0) {
        res += cnt[pos];
        pos -= lowbit(pos);
    }
    return res;
}

ll suffix[maxn];
ll suffix_cnt[maxn], suffix_sum[maxn];
int pre[maxn];

unordered_map<ll, int> pos;
ll ans[maxn];

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n; i >= 1; i--) {
        suffix[i] = suffix[i + 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        suffix_cnt[i] = (n - i + 1) - query_cnt(a[i] - 1);
        suffix_sum[i] = suffix[i] - query_sum(a[i] - 1) - 1LL * a[i] * suffix_cnt[i];
        update(a[i], a[i]);
    }
    set<ll> se;
    set<ll>::iterator iter;
    for (int i = 1; i <= n; i++) {
        iter = se.upper_bound(-a[i]);
        if (iter != se.end()) pre[i] = pos[-(*iter)];
        if (!pos.count(a[i])) pos[a[i]] = i;
        se.insert(-a[i]);
    }
    ll maxvalue = 0, maxpos = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > maxvalue) {
            maxvalue = a[i];
            maxpos = i;
        }
    }
    suffix_sum[0] = suffix[1];
    while (maxpos) {
        int last = pre[maxpos];
        ans[maxpos] += suffix_sum[last] - suffix_sum[maxpos];
        maxpos = last;
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", ans[i]);
    }

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
