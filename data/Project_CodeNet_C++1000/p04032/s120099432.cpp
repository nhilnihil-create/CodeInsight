#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1001001001
#define LINF (1LL << 62)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solv() {
    string str;
    cin >> str;
    char num[3];
    if (str.size() == 2 && str[0] == str[1]) {
        cout << " 1 2\n";
        return;
    }
    rep(i, str.size() - 2) {
        set<char> st;
        st.insert(str[i]);
        st.insert(str[i + 1]);
        st.insert(str[i + 2]);
        if (st.size() < 3) {
            cout << i + 1 << ' ' << i + 3 << endl;
            return;
        }
    }
    cout << "-1 -1" << endl;
}

int main() {
    solv();
    return 0;
}