#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>
#include <cstdint>
#include <complex>
#include <bitset>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n); rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    // 単調性が成り立つことを示す。
    // k - a[i] <= S < k となるSが存在するとすると、
    // a[j] > a[i] を満たす任意のa[j]について、k - a[j] <= S' < k が成り立つようなS'が存在することが示せる。
    // (Sに a[j]が含まれる場合と、a[j]が含まれない場合に分けると示せた。)

    // bitset高速化を付け加えてみた。

    int left = -1;
    int right = n;
    int mid;
    while (right - left > 1) {
        mid = (left + right) / 2;
        bitset<5010> dp;
        dp[0] = 1;

        rep(i, n) {
            if (i != mid) {
                dp = dp | (dp << a[i]);
            }
        }

        bool flag = 0;
        for (int j = max(0, k - a[mid]); j < k; j++) {
            flag |= dp[j];
        }
        if (flag) right = mid;
        else left = mid;
    }

    cout << left + 1 << endl;

    return 0;
}


    