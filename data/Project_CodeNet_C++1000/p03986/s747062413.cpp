#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string X;
    cin >> X;
    stack<char> st;
    for (int i=0;i<X.size();i++){
        if (st.empty()) {
            st.push(X[i]);
            continue;
        }
        if (st.top() == 'S' && X[i] == 'T') {
            st.pop();
        } else {
            st.push(X[i]);
        }
    }
    cout << st.size() << "\n";
}