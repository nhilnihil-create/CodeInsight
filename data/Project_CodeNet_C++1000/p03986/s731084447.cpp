#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

string S;

int main() {
    cin >> S;
    ll N = S.length();

    ll ans = N, cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'S') {
            ++cnt;
        }
        if (S[i] == 'T' && cnt) {
            ans -= 2;
            --cnt;
        }
    }
    cout << ans << endl;
}