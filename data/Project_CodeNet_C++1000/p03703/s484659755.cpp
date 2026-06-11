#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

typedef long long int64;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 10;

int64 a[MAXN];
int64 sum[MAXN];
int64 v[MAXN];

#include <cctype>
#include <cstdio>

inline int read() {
    int X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch)) {
        w |= ch == '-';
        ch = getchar();
    }
    while (isdigit(ch)) {
        X = (X << 3) + (X << 1) + (ch ^ 48);
        ch = getchar();
    }
    return w ? -X : X;
}

int64 ans;
int64 tmp[MAXN];
void merge_sort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1;
    int k = l;
    while (i <= mid && j <= r) {
        if (v[i] <= v[j]) {
            tmp[k++] = v[i++];
            ans += r - j + 1;
        } else {
            tmp[k++] = v[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = v[i++];
    }
    while (j <= r) {
        tmp[k++] = v[j++];
    }
    for (int i = l; i <= r; i++) {
        v[i] = tmp[i];
    }
}

int main() {
    int n = read();
    int64 k = read();
    for (int i = 2; i <= n + 1; i++) {
        a[i] = read();
        sum[i] = sum[i - 1] + a[i];
        v[i] = sum[i] - k * (i - 1);
    }
    merge_sort(1, n + 1);
    cout << ans << endl;
}