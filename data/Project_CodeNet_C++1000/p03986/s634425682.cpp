#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    int cnt = 0;
    for (char c : s) {
        if (c == 'S') st.push(c);
        else if (st.empty()) continue;
        else if (c == 'T') {
            st.pop();
            cnt++;
        }
    }
    cout << s.size() - 2 * cnt << endl;
}
