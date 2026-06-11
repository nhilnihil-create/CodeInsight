#include "bits/stdc++.h"

using namespace std;
using ll = long long;

string S;
int N;

int distance(char c) {
    int Max = 0, d = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == c) {
            Max = max(Max, d);
            d = 0;
        } else {
            ++d;
        }
    }
    return max(Max, d);
}

int main() {
    cin >> S;
    N = S.length();
    set<char> se;
    for (auto c : S)
        se.insert(c);

    int ans = INT_MAX;
    for (auto c : se) {
        ans = min(ans, distance(c));
    }

    cout << ans << endl;
}
