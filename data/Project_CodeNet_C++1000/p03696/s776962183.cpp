#include <bits/stdc++.h>
using namespace std;
vector<int> a;
void solve () {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = s;
    stack<char> st;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == ')') {
            if (st.empty()) {
                ans = '(' + ans;
            } else {
                st.pop();
            }
        } else {
            st.push(')');
        }
    }
    cout << ans;
    for (int i = 0; i < (int) st.size(); i++) {
        cout << ')';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
