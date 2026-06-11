#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef long long ll;

const ll MAX_N = 100005;

ll n, m, a[MAX_N];
ll datas[MAX_N*2]{}, bucket[1000]{},siz = 400;

// [f,e)
void add(int f, int e, ll x) {
    for (int i = 0; i * siz <= m*2+1; i++) {
        int l = i * siz, r = (i + 1) * siz;
        if (f >= r || e <= l)
            continue;
        if (f <= l && e >= r)
            bucket[i] += x;
        else {
            for (int j = max(f, l); j < min(e, r); j++) {
                datas[j] += x;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        ll dif = (m + a[i + 1] - a[i]) % m;
        add(m + a[i + 1] - dif + 1, m + a[i + 1] + 1, 1);
        datas[a[i + 1]] -= dif;
    }
    for (int i = 0; i <= m * 2 + 1; i++) {
        datas[i] += bucket[i / siz];
    }
    for (int i = m * 2 + 1; i > 0; i--) {
        datas[i - 1] += datas[i];
    }
    ll dmin = 99999999999999;
    for (int i = 1; i <= m; i++) {
        if (datas[i] + datas[i + m] < dmin) {
            dmin = datas[i] + datas[i + m];
        }
    }
    cout << dmin << endl;
    return 0;
}