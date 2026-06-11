#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    ll n = s.length();

    rep(i, n) {
        if (s[i] == '0') {
            st.push('0');
        }
        if (s[i] == '1') {
            st.push('1');
        }
        if (s[i] == 'B') {
            if (st.empty())
                continue;
            else
                st.pop();
        }
    }

    stack<char> out;
    while (!st.empty()) {
        out.push(st.top());
        st.pop();
    }

    while (!out.empty()) {
        cout << (char)out.top();
        out.pop();
    }
    cout << endl;

    return 0;
}

