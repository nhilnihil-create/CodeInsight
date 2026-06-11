#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

inline int gcd(int a, int b) { return (a%b == 0) ? b : gcd(b, a%b); }
inline int fac(int n) { return (n==0) ? 1 : n * fac(n - 1); }

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = s.length() - 1; i >= 1; i--)
    {
        string str = s.substr(0, i);
        int l = str.length();
        if (l % 2 == 0) {
            string a = str.substr(0, l / 2);
            string b = str.substr(l / 2, l /2);
            if (a == b) {
                cnt = l;
                break;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
