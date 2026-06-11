#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const double PI = acos(-1.0);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

int main() {
    int n; cin >> n;
    vector<int> a(n); rep(i, n) cin >> a[i];

    // pattern 1 -1 1 -1
    int sum = 0;
    ll cnt_a = 0;
    rep(i, n) {
        sum += a[i];
        // 偶数番目で正の整数ではない場合
        if (i % 2 == 0 && sum < 1) {
            cnt_a += 1 - sum; // ギリギリ正の整数(1)にするために必要な数を加算
            sum = 1;
        }
        // 奇数番目で負の整数ではない場合
        if (i % 2 == 1 && sum > -1) {
            cnt_a += sum + 1; // ギリギリ負の整数(-1)にするために必要な数を加算
            sum = -1;
        }
    }

    // pattern -1 1 -1 1
    sum = 0;
    ll cnt_b = 0;
    rep(i, n) {
        sum += a[i];
        // 偶数番目で負の整数ではない場合
        if (i % 2 == 0 && sum > -1) {
            cnt_b += sum + 1; // ギリギリ負の整数(-1)にするために必要な数を加算
            sum = -1;
        }
        // 奇数番目で正の整数ではない場合
        if (i % 2 == 1 && sum < 1) {
            cnt_b += 1 - sum; // ギリギリ正の整数(1)にするために必要な数を加算
            sum = 1;
        }
    }

    cout << min(cnt_a, cnt_b) << endl;
    return 0;
}
