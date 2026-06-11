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
    ll N, x;
    cin >> N >> x;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll res = 0;
    for(int i = 1; i < N; i++) {
        if(A[i - 1] + A[i] > x) {
            res += A[i] - max(0LL, x - A[i - 1]);
            A[i] = max(0LL, x - A[i - 1]);
        }
        if(A[i] == 0 && A[i - 1] > x) {
            res += A[i - 1] - x;
            A[i - 1] = x;
        }
    }
    cout << res << endl;
    return 0;
}