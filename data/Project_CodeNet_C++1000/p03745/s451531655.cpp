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
    int N;
    cin >> N;
    int         ans = 0;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    FOR(i, 0, N) {
        while (i + 1 < N && A.at(i) == A.at(i + 1)) {
            ++i;
        }
        if (i + 1 < N && A.at(i) <= A.at(i + 1)) {
            while (i + 1 < N && A.at(i) <= A.at(i + 1)) {
                ++i;
            }
        } else if (i + 1 < N && A.at(i) >= A.at(i + 1)) {
            while (i + 1 < N && A.at(i) >= A.at(i + 1)) {
                ++i;
            }
        }
        ++ans;
    }
    cout << ans << endl;
}
