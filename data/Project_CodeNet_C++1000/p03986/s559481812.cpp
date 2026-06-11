#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s; cin >> s;
    stack<int> st;
    for (char c : s) {
        if (c=='T') {
            if (!st.empty()&&st.top()=='S') {
                st.pop();
            } else {
                st.push(c);
            }
        } else {
            st.push(c);
        }
    }
    cout << st.size();
    return 0;
}