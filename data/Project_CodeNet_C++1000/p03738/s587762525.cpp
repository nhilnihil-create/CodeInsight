#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    vec<string> S(2);
    cin >> S[0] >> S[1];
    if (S[0].size() > S[1].size()) {
        cout << "GREATER" << endl;
    } else if (S[0].size() < S[1].size()) {
        cout << "LESS" << endl;
    } else if (S[0] == S[1]) {
        cout << "EQUAL" << endl;
    } else {
        string A = S[0];
        sort(all(S));
        if (A == S[0]) {
            cout << "LESS" << endl;
        } else {
            cout << "GREATER" << endl;
        }
    }
}
