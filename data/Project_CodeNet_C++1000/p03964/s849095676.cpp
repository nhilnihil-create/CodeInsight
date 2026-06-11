#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1001001001
#define LINF (1LL << 62)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solv() {
    int N;
    ll a = 1, b = 1;
    cin >> N;
    rep(i, N) {
        ll buf, buf2;
        cin >> buf >> buf2;
        ll n = max((a + (buf - 1) )/ buf, (b + (buf2 - 1) )/ buf2);
        a = buf * n;
        b = buf2 * n;
    }
    cout << a + b << endl;
}

int main() {
    solv();
    return 0;
}