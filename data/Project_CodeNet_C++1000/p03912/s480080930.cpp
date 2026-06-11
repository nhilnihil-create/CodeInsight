#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

using pii = pair<int, int>;

int main() {
    int N, M;
    cin >> N >> M;
    map<int, int> c;
    REP(i, N) {
        int X;
        cin >> X;
        ++c[X];
    }

    vector<int> one(M, 0);
    vector<int> two(M, 0);
    for (pii p: c) {
        int X, freq;
        tie(X, freq) = p;
        one[X % M] += freq % 2;
        two[X % M] += freq / 2;
    }

    int result = 0;
    
    REP(i, M) {
        if (i > M - i) {
            break;
        }
        int j = (M - i) % M;
        if (i != j) {
            int k = min(one[i], one[j]);
            result += k;
            one[i] -= k;
            one[j] -= k;
        } else {
            int k = one[i] / 2;
            result += k;
            one[i] -= 2 * k;
        }
    }

    REP(i, M) {
        int j = (M - i) % M;
        int k = min(one[i], 2 * two[j]);
        result += k;
        one[i] -= k;
        two[j] -= (k + 1) / 2;
    }

    REP(i, M) {
        int k = two[i];
        result += k;
        two[i] -= k;
    }

    cout << result << endl;

    return 0;
}