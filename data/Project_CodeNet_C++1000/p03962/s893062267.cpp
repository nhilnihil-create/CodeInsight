#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int t;
unordered_set<int> st;
int main() {
    for (int i = 0; i < 3; ++i) {
        cin >> t;
        st.insert(t);
    }
    cout << st.size() << endl;
    return 0;
}
