// {{{
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
// }}}

using ll = long long;

int N, X[505];

pair<int, int> req[505];
int reqa[500*500+5];
int res[500*500+5];
int counts[505];
queue<int> que;

int main() {
    cin >> N; for (int j = 0; j < N; ++j) { cin >> X[j]; --X[j]; }
    fill(reqa, reqa+N*N, 0);
    fill(res, res+N*N, 0);
    fill(counts, counts+N+1, 0);
    for (int j = 0; j < N; ++j) {
        res[X[j]] = reqa[X[j]] = j+1;
        req[j] = make_pair(X[j], j+1);
    }
    sort(req, req+N);

    bool ok = true;
    int idx = 0;
    if (req[0].second == 1) ++idx;
    for (int j = 0; ok && j < N*N; ++j) {
        if (reqa[j] > 0) {
            int num = reqa[j];
            if (++counts[num] < num) {
                ok = false;
            } else {
                for (int n = N-num; n > 0; --n) que.push(num);
            }
        } else if (idx < N) {
            int num = req[idx].second;
            if (counts[num] < num-1) {
                ++counts[num];
                res[j] = num;
            }
            if (counts[num] == num-1) {
                ++idx;
                if (idx < N && req[idx].second == 1) ++idx;
            }
        } else if (que.empty()) {
            ok = false;
        } else {
            res[j] = que.front(); que.pop();
        }
    }

    if (!ok) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int j = 0; j < N*N; ++j) {
            if (j > 0) cout << " ";
            cout << res[j];
        }
        cout << endl;
    }

    return 0;
}
