#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int max_i = 0;
    stack<int> st;
    for (; max_i * (max_i + 1) < 2 * n; max_i++);
    for (int i = max_i; i > 0; i--) {
        if ((i - 1) * i < 2 * n) {
            st.push(i);
            n -= i;
        }
    }
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}

