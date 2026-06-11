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

constexpr int MAXB = 100010;

int main() {
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> cnt(MAXB, 0);
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        cnt[a] += b;
    }
    
    rep(i, MAXB) {
        if (K > cnt[i]) {
            K -= cnt[i];
        } else {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
