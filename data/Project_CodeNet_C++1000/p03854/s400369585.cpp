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
    string S;
    cin >> S;
    int e = S.size();
    while (e > 0) {
        /* dream dreamer erase eraser */
        if (S.substr(e - 2, 2) == "er") {
            if (S.substr(e - 6, 6) == "eraser") {
                e -= 6;
                continue;
            } else if (S.substr(e - 7, 7) == "dreamer") {
                e -= 7;
                continue;
            }
        }
        if (S.substr(e - 5, 5) == "erase") {
            e -= 5;
            continue;
        } else if (S.substr(e - 5, 5) == "dream") {
            e -= 5;
            continue;
        } else {
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
}
