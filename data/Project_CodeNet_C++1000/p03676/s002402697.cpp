#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

const int maxN = 2e5 + 10, modP = 1e9 + 7;

#define FORU(i, l, r) for (int i = l; i <= r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPU(i, r) for (int i = 0; i < r; ++i)
#define LL long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define PINT pair < int, int >
#define NUM_SET_BIT __builtin_popcountll
#define BIT(x, i) ((x >> i) & 1)

int n, p1, p2, POW[maxN], INVERSE_POW[maxN], a[maxN], c[maxN];

void gcd_extended(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0, y = 1;
        return;
    }
 
    int x1, y1; 
    gcd_extended(b % a, a, x1, y1);
 
    x = y1 - (b/a) * x1;
    y = x1;
}

int modulo_inverse(int a) {
    int x, y;
    gcd_extended(a, modP, x, y);
    return ((x % modP + modP) % modP);
}

int nCk(int n, int k) {
    int tmp = (1ll * POW[n] * INVERSE_POW[n - k]) % modP;
    return (1ll * tmp * INVERSE_POW[k]) % modP;
}

int main() {
    cin >> n;
    FORU(i, 1, n + 1) {
        cin >> a[i];
        if (c[a[i]]) p1 = c[a[i]], p2 = i;
        c[a[i]] = i;
    }
    POW[0] = INVERSE_POW[0] = 1;
    FORU(i, 1, n + 1) {
        POW[i] = (1ll * POW[i - 1] * i) % modP;
        INVERSE_POW[i] = modulo_inverse(POW[i]);
    }
    FORU(i, 1, n + 1) {
        int res = nCk(n + 1, i);
        res = (res - nCk(n + 1 - (p2 - p1 + 1), i - 1)) % modP;
        res = (res + modP) % modP;
        cout << res << endl;
    }
}
