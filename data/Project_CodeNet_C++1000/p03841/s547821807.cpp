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
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> x(N);
    rep(i, N) {
        cin >> x[i];
        --x[i];
    }
    vector<int> a(N * N, -1), b(N * N, -1);
    rep(i, N) {
        a[x[i]] = i;
        b[x[i]] = i;
    }
    rep(i, N * N) {
        if (a[i] == -1) continue;
        int now = 0;
        rep(j, a[i]) {
            while (b[now] != -1) ++now;
            if (now > i) {
                cout << "No\n";
                return 0;
            }
            b[now] = a[i];
        }
    }
    for (int i = N * N - 1; i >= 0; --i) {
        if (a[i] == -1) continue;
        int now = N * N - 1;
        rep(j, N - 1 - a[i]) {
            while (b[now] != -1) --now;
            if (now < i) {
                cout << "No\n";
                return 0;
            }
            b[now] = a[i];
        }
    }
    cout << "Yes\n";
    rep(i, N * N) cout << b[i] + 1 << "\n";
    return 0;
}
