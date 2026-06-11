#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll A, B, C;
int main() {
    cin >> A >> B >> C;
    ll even = 0;

    if (A % 2 == 0) even++;
    if (B % 2 == 0) even++;
    if (C % 2 == 0) even++;

    if (even >= 1) {
        cout << 0 << endl;
        return 0;
    }

    // 全部奇数の時
    // ll max_v = A;
    // max_v = max(max_v, B);
    // max_v = max(max_v, C);
    vector<ll> v = {A, B, C};
    sort(v.begin(), v.end());

    ll red = v[0] * v[1] * (v[2] / 2);
    ll blue = v[0] * v[1] * (v[2] / 2 + 1);
    // cout << red <<  " " << blue << endl;
    cout << blue - red << endl;
}