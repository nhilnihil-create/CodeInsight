#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

#define dbg(x1) cout<<#x1<<" = "<<(x1)<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<" "<<#x3<<" = "<<(x3)<<endl
ll a[maxn], bit_tree[2 * maxn];
ll lowbit(ll x) {return x & (-x);}
void update(ll pos, ll x) {
    while (pos <= 400000) {
        bit_tree[pos] += x;
        pos += lowbit(pos);
    }
}
ll query(ll pos) {
    ll res = 0;
    while (pos > 0) {
        res += bit_tree[pos];
        pos -= lowbit(pos);
    }
    return res;
}
ll prefix[maxn];
ll num[2 * maxn];
unordered_map<ll, int> mp;
int main() {
    //freopen(".in", "r", stdin);
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + a[i];
    for (int i = 1; i <= n; i++) prefix[i] -= 1LL * k * i;
    int cnt = 1;
    num[1] = 0;
    for (int i = 1; i <= n; i++) {
        num[++cnt] = prefix[i];
    }
    sort(num + 1, num + 1 + cnt);
    cnt = unique(num + 1, num + 1 + cnt) - num - 1;
    for (int i = 1; i <= cnt; i++) mp[num[i]] = i;
    update(mp[0], 1);
    ll ans = 0;
    for (int r = 1; r <= n; r++) {
        ans += query(mp[prefix[r]]);
        update(mp[prefix[r]], 1);
    }
    printf("%lld\n", ans);
    return 0;
}

