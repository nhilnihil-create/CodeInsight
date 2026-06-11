#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>

using namespace std;
using ll = long long;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const double PI = acos(-1.0);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

int main() {
    int N; cin >> N; // 1日あたりに到着する乗客の数
    int C; cin >> C; // バスの定員
    int K; cin >> K; // 経過時間のリミット
    vector<int> T(N); rep(i, N) cin >> T[i];  // 乗客の到着時刻
    sort(T.begin(), T.end());

    int ans = 0;

    for (int i = 0; i < N;) {
        ++ans;
        int start = i;
        while (i < N && T[i] - T[start] <= K && i - start < C) ++i;
    }

    cout << ans << endl;
    return 0;
}
