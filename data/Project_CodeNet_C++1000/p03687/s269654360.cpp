#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    string s;
    cin >> s;
    
    set<char> st;
    for (ll i = 0; i < s.length(); i++) {
        st.insert(s[i]);
    }
    
    if(st.size() == 1) {
        cout << 0 << endl;
        return 0;
    }


    ll ans = 100, cnt;
    for (auto key = st.begin(); key != st.end(); key++) {
        string str = s;
        bool flag = true;
        cnt = 1;

        while (flag) {
            string vacant;
            flag = false;
            for (ll i = 0; i < str.length()-1; i++) {
                if (str[i] == *key || str[i+1] == *key) {
                    vacant += *key;
                } else {
                    vacant += str[i];
                    flag = true;
                }
            }
            if (flag) {
                str = vacant;
                cnt ++;
            }
        }

        ans = min(ans, cnt);
    }


    cout << ans << endl;
    return 0;
}