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
    rep(i, N) cin >> x[i];
    int L;
    cin >> L;
    
    vector<vector<int>> NEXT(20, vector<int>(N));
    rep(i, N) NEXT[0][i] = upper_bound(x.begin(), x.end(), x[i] + L) - 1 - x.begin();
    for (int i = 1; i < 20; ++i) rep(j, N) NEXT[i][j] = NEXT[i - 1][NEXT[i - 1][j]];
    
    int Q;
    cin >> Q;
    rep(q, Q) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (a > b) swap(a, b);
        int left = 0;
        int right = N;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            int now = a;
            rep(i, 20) {
                if (mid & (1 << i)) now = NEXT[i][now];
            }
            if (now >= b) right = mid;
            else left = mid;
        }
        cout << right << "\n";
    }
    return 0;
}
