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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    for(char& c : s) c -= ('A' - 1);
    for(char& c : t) c -= ('A' - 1);
    s.insert(s.begin(), 0);
    t.insert(t.begin(), 0);
    vector<int> ss(s.size()), tt(t.size());
    copy(s.begin(), s.end(), ss.begin());
    copy(t.begin(), t.end(), tt.begin());
    partial_sum(ss.begin(), ss.end(), ss.begin());
    partial_sum(tt.begin(), tt.end(), tt.begin());
    int q;
    cin >> q;
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << ((ss[b] - ss[a-1]) % 3 == (tt[d] - tt[c-1]) % 3? "YES" : "NO") << endl;
    }
    return 0;
}
