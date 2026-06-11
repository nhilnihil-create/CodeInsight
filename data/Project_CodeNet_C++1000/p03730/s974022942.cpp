#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

int A, B, C;
int main() {
    cin >> A >> B >> C;

    ll tmp = 0;
    for (int i = 0; i < 6000; i++) {
        tmp = A * i;
        if (tmp % B == C) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}