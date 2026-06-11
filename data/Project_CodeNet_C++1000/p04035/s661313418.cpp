#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    ll N, L;
    cin >> N >> L;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }
    int s = -1;
    rep(i, N - 1) {
        if(A[i] + A[i + 1] >= L)
            s = i;
    }
    if(s == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        for(int i = 0; i < s; i++) {
            cout << i + 1 << endl;
        }
        for(int i = N - 2; i > s; i--) {
            cout << i + 1 << endl;
        }
        cout << s + 1 << endl;
    }

    return 0;
}