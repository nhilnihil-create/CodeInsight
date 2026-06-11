#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

ll dist(ll a, ll b, ll c, ll d) {
    return abs(a-c) + abs(b-d);
}

int main() {
    int N, M;
    vector<pair<ll, ll>> stu, point;
    ll buf1, buf2;

    cin >> N >> M;

    rep (i, N) {
        cin >> buf1 >> buf2;
        stu.push_back(make_pair(buf1, buf2));
    }

    rep (i, M) {
        cin >> buf1 >> buf2;
        point.push_back(make_pair(buf1, buf2));
    }

    ll ans, count, near_dist;
    for (pair<ll, ll> s: stu) {
        ans = 0;
        count = 0;
        near_dist = INF;
        for (pair<ll, ll> p : point) {
            ll tmp = dist(s.first, s.second, p.first, p.second);
            if (near_dist > tmp) {
                ans = count+1;
                near_dist = tmp;
            }
            count++;
        }
        cout << ans << endl;
    }

}
