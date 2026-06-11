#include <bits/stdc++.h>
using namespace std;

//const double PI = acos(-1);
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second

const int n = 26;
string s, ans;
set<char> st;
char a[200010];
char c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    REP(i,sz(s)+1) a[i] = 'a';
    for (int i = sz(s) - 1; i >= 0; i--) {
            st.insert(s[i]);
            REP(j,n) {
                if (!st.count((char)('a' + j))) {
                    a[i] = (char)('a' + j);
                    break;
                }
            }
            if (sz(st) == n) {
                st.clear();
                a[i] = 'a';
            }
    }
//    REP(i,sz(s)) cout << a[i];
//    cout << endl;
    REP(i,sz(s)) {
        if (!sz(ans)) {
            ans = a[i];
            c = a[i];
            if (c == s[i]) i--;
            continue;
        }
        if (s[i] != c) {}
        else {
            ans += a[i+1];
            c = a[i+1];
        }
    }

    cout << ans << endl;
    return 0;
}
