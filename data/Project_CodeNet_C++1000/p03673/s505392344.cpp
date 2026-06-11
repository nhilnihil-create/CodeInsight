#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vi b;
    for (int i = n - 1; i >= 0; i -= 2) {
        b.push_back(a[i]);
    }
    for (int i = n % 2; i < n; i += 2) {
        b.push_back(a[i]);
    }
    rep(i, n) {
        printf("%d ", b[i]);
    }
    printf("\n");
}