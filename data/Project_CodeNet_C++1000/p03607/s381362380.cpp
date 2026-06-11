#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

ll dist(ll a, ll b, ll c, ll d) {
    return abs(a-c) + abs(b-d);
}

int main() {
    map<string, int> m;
    string buf;
    int N;

    cin >> N;

    rep (i, N) {
        cin >> buf;

        if (m.find(buf) == m.end()) {
            m.insert(make_pair(buf, 0));
        } else {
            m.erase(buf);
        }
    }

    cout << m.size() << endl;
}
