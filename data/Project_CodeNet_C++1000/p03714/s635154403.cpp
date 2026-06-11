#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP(i, n) for (int i = 1; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    int N;
    cin >> N;
    vector<int> a(3 * N);
    rep(i, 3 * N) cin >> a[i];
    
    priority_queue<int, vector<int>, greater<int>> p;
    lint sum = 0;
    rep(i, N) {
        sum += a[i];
        p.push(a[i]);
    }
    vector<lint> S(N + 1, 0);
    S[0] = sum;
    rep(i, N) {
        int x = p.top();
        p.pop();
        if (x < a[N + i]) {
            sum -= x;
            sum += a[N + i];
            p.push(a[N + i]);
        } else {
            p.push(x);
        }
        S[i + 1] = sum;
    }
    reverse(a.begin(), a.end());
    priority_queue<int> q;
    sum = 0;
    rep(i, N) {
        sum += a[i];
        q.push(a[i]);
    }
    vector<lint> T(N + 1, 0);
    T[0] = sum;
    rep(i, N) {
        int x = q.top();
        q.pop();
        if (x > a[N + i]) {
            sum -= x;
            sum += a[N + i];
            q.push(a[N + i]);
        } else {
            q.push(x);
        }
        T[i + 1] = sum;
    }
    reverse(T.begin(), T.end());
    lint ans = -1000000000000000;
    rep(i, N + 1) ans = max(ans, S[i] - T[i]);
    cout << ans << "\n";
    return 0;
}
