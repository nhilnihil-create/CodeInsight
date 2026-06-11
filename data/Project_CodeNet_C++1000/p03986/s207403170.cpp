#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<int> st;
    int no_rem = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'S') {
            st.push(0);
        } else {
            if (!st.empty()) {
                no_rem++;
                st.pop();
            }
        }
    }
    cout << s.length() - no_rem * 2;
}