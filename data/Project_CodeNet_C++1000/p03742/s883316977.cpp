#include <iostream>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

const int MOD = (int) 1e9 + 7;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll x, y;
    cin >> x >> y;

    if (abs(x - y) <= 1) cout << "Brown" << endl;
    else cout << "Alice" << endl;
    return 0;
}