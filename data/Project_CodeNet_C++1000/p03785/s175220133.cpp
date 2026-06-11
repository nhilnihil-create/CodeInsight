#include <bits/stdc++.h>
#define INF 1e9
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define FORE(i, a, b) for (int i = (a), e = (b); i < e; ++i)
#define RFORE(i, a, b) for (int i = (b)-1, e = (a); i >= e; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(c) sort((c).begin(), (c).end())
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T.at(i);
    }
    SORT(T);
    int ans = 0;
    for (int i = 0; i < N;) {
        int passenger = 0;
        int first     = T.at(i);
        int end       = T.at(i);
        while ((i < N) && (C > passenger)) {
            end = T.at(i);
            if (K < end - first) { break; }
            ++passenger;
            ++i;
        }
        ++ans;
    }
    cout << ans << endl;
}
