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

    vector<bool> alpha(26);
    rep(i, s.size()) {
        alpha[s[i] - 'a'] = 1;
    }

    int ans = 1e9;
    int ch = 0;
    repd(i, 1, s.size()) {
        if (s[i] == s[i - 1]) ch++;
    }

    if (ch + 1 == (int)s.size()) ans = 0;
    rep(j, 26) {
        bool flag = true;
        int cnt = 0;
        string t, check = s;
        if (!alpha[j]) continue;
        while (flag && (int)check.size() >= 2) {
            char ct = 'a' + j;
            // cout << ct << " ";
            t = check;
            check = "";
            repd(i, 1, t.size()) {
                if (t[i] == ct || t[i - 1] == ct) {
                    check += ct;
                }
                else {
                    check += t[i];
                }
            }
            repd(i, 1, check.size()) {
                if (check[i] == check[i - 1]) flag = false;
                else {
                    flag = true;
                    break;
                } 
            }
            cnt++;
        }
        chmin(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}