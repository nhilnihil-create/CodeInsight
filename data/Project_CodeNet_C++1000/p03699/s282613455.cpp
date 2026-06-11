#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

ll dist(ll a, ll b, ll c, ll d) {
    return abs(a-c) + abs(b-d);
}

int main() {
    int N;
    int sum = 0, buf;
    vector<int> list;

    cin >> N;

    rep (i, N) {
        cin >> buf;
        sum += buf;
        if (buf%10 != 0) {
            list.push_back(buf);
        }
    }

    if (sum%10 != 0) {
        cout << sum << endl;
    } else {
        if (list.size() == 0) {
            cout << 0 << endl;
        } else {
            sort(list.begin(), list.end());
            cout << sum-list[0] << endl;
        }
    }

}
