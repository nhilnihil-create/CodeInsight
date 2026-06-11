#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
using ll = int64_t;
using ull = uint64_t;
using namespace std;

int main() {
    fastIO;
    size_t N;
    string s, t;
    cin >> N;
    cin >> s >> t;

    for (size_t i = 0; i < N; i++) {
        bool isMatch = true;
        for (size_t j = i; j < N; j++) {
            // cout << s.at(j) << " " << t.at(j - i) << endl;
            if (s.at(j) != t.at(j - i)) {
                isMatch = false;
            }
        }

        if (isMatch) {
            cout << (N - i) + i * 2 << endl;
            return 0;
        }
    }
    cout << N * 2;
}