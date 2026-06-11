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
    string S;
    cin >> S;

    int ans = 1e9;
    int len = (int)S.size();
    rep(h, len) {
        char ct = S[h];
        int cnt = 0;
        string s = S;
        while (1) {
            string t = "";
            bool flag = true;
            repd(i, 1, s.size()) {
                if (s[i - 1] != s[i]) flag = false;
            }
            if (flag) break;
            repd(i, 1, s.size()) {
                if (s[i - 1] == ct || s[i] == ct) t += ct;
                else t += s[i];
            }
            s = t;
            cnt++;
        }
        chmin(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}