#include <bits/stdc++.h>
using namespace std;

bool match(char c1, char c2) {
    return c1 == 'S' && c2 == 'T';
}

int main() {
    string X;  cin >> X;
    int N = X.size();
    stack<char> st;
    for (int i = 0; i < N; ++i) {
        if (!st.empty() && match(st.top(), X[i])) st.pop();
        else st.push(X[i]);
    }
    cout << st.size() << endl;
}
