#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    ll power = 1;
    rep(i, N) {
        power *= (i + 1);
        power %= MOD;
    }

    cout << power << endl;
    return 0;
}