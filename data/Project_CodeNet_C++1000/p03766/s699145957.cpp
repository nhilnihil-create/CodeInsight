#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

typedef pair<int, int> pii;
const int N = int(1e6 + 2);
const int mod = int(1e9 + 7);

void add(int& x, int y) {if((x += y) >= mod) x -= mod;}
int mul(int x, int y) {return 1ll * x * y % mod;}

unsigned int f[N], sum[N], n;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    f[0] = sum[0] = 1;
    f[1] = n, sum[1] = n + 1;
    f[2] = mul(n, n);
    sum[2] = f[2] + sum[1];
    if(sum[2] >= mod) sum[2] -= mod;
    for(int i = 3; i <= n; ++i) {
        f[i] = f[i - 1] + mul(n - 1, n - 1) + sum[i - 3] + (n - i + 1);
        if(f[i] >= mod) f[i] %= mod;
        sum[i] = sum[i - 1] + f[i];
        if(sum[i] >= mod) sum[i] -= mod;
    }
    cout << f[n];
}
