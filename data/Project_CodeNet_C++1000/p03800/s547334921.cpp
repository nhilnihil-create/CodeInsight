#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    int N;
    string s;
    cin >> N >> s;

    // 1, 2, N
    vector<tuple<char,char,char>> inits;
    if (s[0] == 'o') {
        inits.push_back(make_tuple('S', 'S', 'S'));
        inits.push_back(make_tuple('S', 'W', 'W'));
        inits.push_back(make_tuple('W', 'S', 'W'));
        inits.push_back(make_tuple('W', 'W', 'S'));
    } else {
        inits.push_back(make_tuple('S', 'S', 'W'));
        inits.push_back(make_tuple('S', 'W', 'S'));
        inits.push_back(make_tuple('W', 'S', 'S'));
        inits.push_back(make_tuple('W', 'W', 'W'));
    }
    bool is_ok = false;
    vector<char> a(N);
    for (auto init : inits) {
        a = vector<char>(N);
        a[0] = get<0>(init);
        a[1] = get<1>(init);
        char a_N = get<2>(init);
        for (int i = 1; i < N - 1; i++) {
            if (a[i] == 'S') {
                if (s[i] == 'o') {
                    a[i + 1] = a[i - 1];
                } else {
                    a[i + 1] = a[i - 1] == 'S' ? 'W' : 'S';
                }
            } else { // 'W'
                if (s[i] == 'o') {
                    a[i + 1] = a[i - 1] == 'S' ? 'W' : 'S';
                } else {
                    a[i + 1] = a[i - 1];
                }
            }
        }
        if (a[N - 1] != a_N) continue;
        if (a[N - 1] == 'S') {
            if (s[N - 1] == 'o') {
                if (a[N - 2] == a[0]) { is_ok = true; break; }
            } else {
                if (a[N - 2] != a[0]) { is_ok = true; break; }
            }
        } else { // 'W'
            if (s[N - 1] == 'o') {
                if (a[N - 2] != a[0]) { is_ok = true; break; }
            } else {
                if (a[N - 2] == a[0]) { is_ok = true; break; }
            }
        }
    }
    if (is_ok) {
        for (char c : a) cout << c;
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}