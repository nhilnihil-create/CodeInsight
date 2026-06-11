#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    string S; int K; cin >> S >> K;

    REP(i, 0, S.size()) {
        // cout << i << " : " << K << endl;
        if (S[i] == 'a') continue;

        if ('a' + 26 - S[i] <= K) {
            K -= ('a' + 26 - S[i]);
            S[i] = 'a';
        }
    }

    if (K > 0) {
        S[S.size() - 1] = (S[S.size() - 1] - 'a' + K) % 26 + 'a';
    }

    cout << S << endl;
    return 0;
}