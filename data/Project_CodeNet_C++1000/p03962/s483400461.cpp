#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    set<int> st;

    st.insert(a);
    st.insert(b);
    st.insert(c);

    cout << st.size() << endl;
    
    return 0;
}