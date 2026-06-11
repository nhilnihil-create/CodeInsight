#include <bits/stdc++.h>
using namespace std;

template <class t>
using vc = vector<t>;
template <class t>
using vvc = vector<vector<t>>;
typedef long long ll;
typedef vc<int> vi;
typedef vvc<int> vvi;
typedef pair<int, int> pi;

#define endl "\n"

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()

#define ALL(a) a.bg, a.ed

template <class t, class u>
ostream &operator<<(ostream &os, const pair<t, u> &p) {
    return os << "( " << p.k << ", " << p.v << " )";
}

template <class t>
ostream &operator<<(ostream &os, const vc<t> &v) {
    os << "[ ";
    for (int i = 0; i < v.size(); i++) {
        os << v[i];
        if (i != v.size() - 1) {
            os << ", ";
        }
    }
    return os << " ]";
}

// g++ -std=c++17 -O2 -Wall template.cpp -o template
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout << fixed << setprecision(18);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // Solution
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = n; 0 <= i; i--) {
        if (s.find(t.substr(0, i)) != string::npos) {
            cout << n + (n - i) << endl;
            return 0;
        }
    }
    cout << 2 * n << endl;
}
