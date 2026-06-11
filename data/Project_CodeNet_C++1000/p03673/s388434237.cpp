#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) { cin >> a[i]; }

    vector<ll> b(N, 0);
    // rep(i, N) {
    //     b.push_back(a[i]);
    //     reverse(begin(b), end(b));
    // }

    if (N % 2 == 0) {
        ll left = N / 2 - 1;
        ll right = N / 2;
        for (ll i = 1; i <= N; i++) {
            if (i % 2 == 1) {
                b[right] = a[i - 1];
                right++;
            } else {
                b[left] = a[i - 1];
                left--;
            }
        }
    } else {
        ll left = N / 2;
        ll right = N / 2 + 1;
        for (ll i = 1; i <= N; i++) {
            if (i % 2 == 1) {
                b[left] = a[i - 1];
                left--;
            } else {
                b[right] = a[i - 1];
                right++;
            }
        }
    }
    repv(b) { cout << *it << " "; }
    cout << endl;
    return 0;
}