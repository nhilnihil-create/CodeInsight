#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
const int MAX_N = 2e5;
int bit[MAX_N + 2];
ll b[MAX_N + 1], c[MAX_N + 1];

void add(int i) {
    for (int j = i; j <= n + 1; j += j & -j) {
        bit[j]++;
    }
}

ll sum(int i) {
    ll rv = 0;
    for (int j = i; j > 0; j -= j & -j) {
        rv += bit[j];
    }
    return rv;
}

int main() {
    int  k;
    cin >> n >> k;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        b[i + 1] = b[i] + a - k;
        c[i + 1] = b[i + 1];
    }

    // 座標圧縮
    sort(c, c + n + 1);
    for (int i = 0; i <= n; i++) {  //b[i] <- index of b[i] in c
        int inf = 0, sup = n + 1;
        while (sup - inf > 1) {
            int mid = (inf + sup) / 2;
            if (c[mid] <= b[i])
                inf = mid;
            else
                sup = mid;
        }
        b[i] = sup;
    }
    ll ans = 0;
    // Binary Indexed Tree (Fenwick Tree)
    for (int i = 0; i < n + 1; i++) {
        ans += sum(b[i]);
        add(b[i]);
    }
    cout << ans << endl;
}
