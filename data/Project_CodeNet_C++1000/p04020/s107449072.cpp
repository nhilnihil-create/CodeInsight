// 答えを見た
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;

int flush(queue<int>& q) {
    int ans = 0;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        ans += a;
    }

    return ans / 2;
}

signed main() {
    int N;

    cin >> N;

    vector<int> As(N);
    REP(i, N) {
        cin >> As.at(i);
    }

    int ans = 0;

    // 0になるまで見ていく
    queue<int> q;
    REP(i, N) {
        int a = As.at(i);
        if (a == 0) {
            ans += flush(q);
        } else {
            q.push(a);
        }
    }

    ans += flush(q);

    cout << ans << endl;
}
