#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    for (size_t i = 1; i < s.size() - 1; i++) {
        // even length strings
        int length = (s.size() - i);
        bool is_ans = true;
        if (length % 2 == 0) {
            for (size_t i = 0; i < length / 2; i++) {
                if (s.at(i) != s.at(i + length / 2)) {
                    is_ans = false;
                }
            }
            if (is_ans) {
                cout << length;
                return 0;
            }
        }
    }
}