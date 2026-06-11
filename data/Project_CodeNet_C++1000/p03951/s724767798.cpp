#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> veci;
typedef vector<long long> vecll;
typedef vector<unsigned long long> vecull;

int N;
string s, t;

int main(void) {
    cin >> N >> s >> t;

    int ans = 2 * N;
    for(int i = N; i < 2 * N; ++i) {
        string ss = s.substr(i - N, 2 * N - i);
        string tt = t.substr(0, 2 * N - i);

        if (ss == tt) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}