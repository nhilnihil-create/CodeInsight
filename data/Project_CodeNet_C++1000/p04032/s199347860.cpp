#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    string s;
    cin >> s;

    rep(i, (int)s.size() - 1) {
        if (s[i] == s[i + 1]) {
            cout << i + 1 << " " << i + 2 << endl;
            return 0;
        }
    }

    rep(i, (int)s.size() - 2) {
        if (s[i] == s[i + 2]) {
            cout << i + 1 << " " << i + 3 << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;
    return 0;
}