#include <bits/stdc++.h>
using namespace std;

signed main () {
    string str;
    cin >> str;
    int n = str.size();
    stack < char > st;
    for (int i = 0; i < n; ++i) {
        if (st.empty() || !(st.top() == 'S' && str[i] == 'T'))
            st.push(str[i]);
        else
            st.pop();
    }
    cout << st.size() << '\n';
}
