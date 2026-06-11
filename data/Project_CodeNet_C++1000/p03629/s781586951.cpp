#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
const int N = 200'000;
int opt[N+2], nex[N+1][26];
char action[N+2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    s += 'a';
    for(char& c : s) c -= 'a';
    fill(begin(nex[s.size()]), end(nex[s.size()]), s.size());
    for(int i = s.size() - 1; i >= 0; i--) {
        for(int c = 0; c < 26; c++) {
            nex[i][c] = s[i] == c ? i + 1 : nex[i+1][c];
        }
    }
    for(int i = s.size(); i >= 0; i--) {
        if(i == s.size()) {
            opt[i] = 0;
        } else {
            opt[i] = lim<int>::max();
            for(int c = 0; c < 26; c++) {
                if(opt[i] > 1 + opt[nex[i][c]]) {
                    opt[i] = 1 + opt[nex[i][c]];
                    action[i] = c;
                }
            }
        }
    }
    for(int i = 0; i < s.size(); i = nex[i][action[i]]) {
        cout << char('a' + action[i]);
    }
    cout << endl;
    return 0;
}
