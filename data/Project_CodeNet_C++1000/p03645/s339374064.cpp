#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;


int main() {

    ll N, M;

    cin >> N >> M;

    vector<bool> L(N + 1);
    vector<bool> R(N + 1);
    ll a, b;

    rep(i, M){
        cin >> a >> b;
        if (a == 1 || b == 1) {
            L[max(a, b)] = true;
        }
        if (a == N || b == N) {
            R[min(a, b)] = true;
        }
    }

    bool ans = false;

    rep(i, N + 1) {
        if (L[i] && R[i]) {
            ans = true;
        }
    }

    if (ans) {
        cout << "POSSIBLE";
    }
    else {
        cout << "IMPOSSIBLE";
    }

	return 0;
}
