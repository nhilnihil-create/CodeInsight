#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <unordered_map>

using namespace std;

const int maxN = 1e5 + 10;

#define FORU(i, l, r) for (int i = l; i <= r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPU(i, r) for (int i = 0; i < r; ++i)
#define F first
#define S second
#define PB push_back
#define LL long long
#define BIT(x, i) ((x >> i) & 1)
#define PINT pair < int, int >
#define MP make_pair

int n, a[maxN], res;

int main() {
    cin >> n;
    FORU(i, 1, n) cin >> a[i];
    int p = 0;
    FORU(i, 1, n)
        if (a[i] == i) {
            if (p) p = 0;
            else ++res, p = 1;
        }
        else p = 0;
    cout << res;
}
