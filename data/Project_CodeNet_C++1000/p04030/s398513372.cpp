#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; ++i)
        if (s[i] == 'B' && !st.empty())
            st.pop();
        else if (s[i] != 'B')
            st.push(s[i]);

    s = "";
    while (!st.empty())
    {
        s += st.top();
        st.pop();
    }
    reverse(s.begin(), s.end());
    cout << s;
}