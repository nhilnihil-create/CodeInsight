#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll N; cin >> N;
    string t; cin >> t;

    string s(t.begin(), t.end());
    while (true) {
        bool isok = true;
        rep(i, s.size()-1) {
            if (s[i] == '(' && s[i+1] == ')') {
                s.erase(i, 2);
                isok = false;
                break;
            }
        }
        if (isok || s == "") {
            break;
        }
    }
    //cout << s << endl;

    if (s == "") {
        cout << t << endl;
        return 0;
    }

    ll f = 0, b = 0;
    rep(i, s.size()) {
        if (s[i] == '(') f++;
        else b++;
    }

    rep(i, b) t.insert(t.begin(), '(');
    rep(i, f) t.push_back(')');

    cout << t << endl;
    return 0;
}