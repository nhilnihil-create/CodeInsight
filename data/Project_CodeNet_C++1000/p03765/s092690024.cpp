#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int N = S.length(), M = T.length();
    vector<int> cnts(N + 1, 0), cntt(M + 1, 0);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') {
            cnts[i + 1] += cnts[i] + 1;
        } else {
            cnts[i + 1] += cnts[i] + 2;
        }
    }
    for (int i = 0; i < M; i++) {
        if (T[i] == 'A') {
            cntt[i + 1] += cntt[i] + 1;
        } else {
            cntt[i + 1] += cntt[i] + 2;
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((cnts[b] - cnts[a - 1]) % 3 == (cntt[d] - cntt[c - 1]) % 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
