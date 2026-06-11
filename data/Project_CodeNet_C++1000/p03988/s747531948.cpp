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
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    
    sort(ALL(A));
    if (A[0] < (A[N - 1] + 1) / 2) {
        cout << "Impossible\n";
        return 0;
    }
    vector<int> cnt(N, 0);
    REP(i, N) ++cnt[A[i]];
    if (A[N - 1] & 1) {
        if (cnt[(A[N - 1] + 1) / 2] != 2) {
            cout << "Impossible\n";
            return 0;
        }
        for (int i = (A[N - 1] + 1) / 2; i <= A[N - 1]; ++i) {
            if (cnt[i] < 2) {
                cout << "Impossible\n";
                return 0;
            }
        }
    } else {
        if (cnt[(A[N - 1] + 1) / 2] != 1) {
            cout << "Impossible\n";
            return 0;
        }
        for (int i = A[N - 1] / 2 + 1; i <= A[N - 1]; ++i) {
            if (cnt[i] < 2) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }
    cout << "Possible\n";
    return 0;
}
