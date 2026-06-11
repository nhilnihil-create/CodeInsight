#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10;

int n;
int a[MAXN], b[MAXN];

string solve() {
    cin >> n;
    long long suma = 0;
    long long x = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        suma += a[i];
        x += i;
    }
    if (suma % x != 0) return "NO";
    int k = suma / x;
    for(int i = 1; i <= n; ++i) {
        int j = i + 1;
        if (j > n) j = 1;
        long long v = (a[i] + k - a[j]);
        if (v % n != 0) return "NO";
        if (v < 0) return "NO";
        b[i] = v / n;
    }
    return "YES";
}

int main() {
    int ntests = 1;
    //cin >> ntests;
    for(int tc = 1; tc <= ntests; ++tc) {
        cout << solve() << "\n";
    }
}