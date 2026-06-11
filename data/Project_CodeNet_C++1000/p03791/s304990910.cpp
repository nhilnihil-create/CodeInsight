#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <queue>

#define mp make_pair
#define pb push_back
#define FI first
#define SI second


#ifdef _MSC_VER
    #define ALIGN(x) __declspec(align(x))
#else
    #define ALIGN(x) __attribute__((aligned(x)))
#endif


using namespace std;

typedef long long ll;

const int maxn = 100007;
const int mod = 1000000007;

int a[maxn];
int f[maxn];
int st[maxn];
int ans[maxn];
int x[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    f[1] = 1; f[0] = 1;
    for (int i = 2; i <= n; ++i) f[i] = (1ll * f[i - 1] * i) % mod;
    st[0] = 0;
    for (int i = 1; i < n; ++i) {
        int pos = a[i - 1];
        int leave = st[i - 1];
        int x = i - leave - 1;
        if (((x + 1) * 2 - 1) <= pos) {
            st[i] = leave;
        } else {
            st[i] = leave + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        x[st[i] + 1] += 1;
    }
    for (int i = 1; i <= n; ++i) {
        x[i] += x[i - 1];
    }
    int res = 1;
    for (int i = 1; i <= n; ++i)
        res = (1ll * res * (x[i] - i + 1)) % mod;
    cout << res << endl;
    return 0;
}