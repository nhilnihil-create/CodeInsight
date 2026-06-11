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

    int g = 0, p = 0, w = 0, l = 0;
    rep(i, s.size()) {
        if (p + 1 <= g) {
            if (s[i] == 'g') {
                w++;
            }
            p++;
        }
        else {
            if (s[i] == 'p') {
                l++;
            }
            g++;
        }
    }

    cout << w - l << endl;
    return 0;
}