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
    cin >> N;
    vector<int> S;
    int sum = 0;
    rep(i, N) {
        int s;
        cin >> s;
        if (s % 10) S.push_back(s);
        sum += s;
    }
    sort(ALL(S));
    if (sum % 10) {
        cout << sum << "\n";
    } else {
        if (SZ(S)) cout << sum - S[0] << "\n";
        else cout << 0 << "\n";
    }
    return 0;
    return 0;
}
