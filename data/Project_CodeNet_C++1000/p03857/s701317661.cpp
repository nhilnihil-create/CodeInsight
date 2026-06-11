#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

ll n, k, l;
ll p, q;

ll rail[200005];
ll tree[200005];

map<ll, ll> mp[200005];

void init(ll n);
ll   root(ll x, ll tree[]);
void merge(ll a, ll b, ll tree[]);

int main()
{
    scanf("%lld %lld %lld", &n, &k, &l);

    init(n);

    for (int i = 0; i < k; i++) {
        scanf("%lld %lld", &p, &q);

        merge(p, q, rail);
    }

    for (int i = 0; i < l; i++) {
        scanf("%lld %lld", &p, &q);

        merge(p, q, tree);
    }

    for (int i = 1; i <= n; i++) {
        mp[root(i, rail)][root(i, tree)]++;
    }

    for (int i = 1; i <= n; i++) {

        if (i > 1) {
            printf(" %lld", mp[root(i, rail)][root(i, tree)]);
        }
        else {
            printf("%lld", mp[root(i, rail)][root(i, tree)]);
        }
    }
    putchar('\n');

    return 0;
}

void init(ll n)
{
    for (int i = 0; i <= n; i++) {
        tree[i] = -1;
        rail[i] = -1;
    }

    return;
}

ll root(ll x, ll tree[])
{
    if (tree[x] < 0) {
        return x;
    }
    
    tree[x] = root(tree[x], tree);

    return tree[x];
}

void merge(ll a, ll b, ll tree[])
{
    a = root(a, tree);
    b = root(b, tree);

    if (a != b) {
        tree[a] += tree[b];
        tree[b] = a;
    }

    return;
}
