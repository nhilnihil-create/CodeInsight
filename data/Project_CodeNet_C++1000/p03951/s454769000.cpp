#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

inline int gcd(int a, int b) { if (a%b == 0) { return b; } else { return gcd(b, a%b); } }

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;

    for (int i = 0; i < min(s.length(), t.length()); i++) {
        string s_sub = s.substr(i, n);
        string t_sub = t.substr(0, n - i);
        if (s_sub.compare(t_sub) == 0) {
            cout << t.length() + i << endl;
            return 0;
        }
    }

    cout << 2 * n << endl;
    return 0;
}