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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;

int main() {
    int N;
    cin >> N;
    deque<int> dq;
    rep(i, N) {
        int a;
        cin >> a;
        if (i & 1) dq.push_front(a);
        else dq.push_back(a);
    }
    if (N & 1) {
        rep(i, N) {
            cout << dq.back() << " \n"[i == N - 1];
            dq.pop_back();
        }
    } else {
        rep(i, N) {
            cout << dq.front() << " \n"[i == N - 1];
            dq.pop_front();
        }
    }
    return 0;
}
