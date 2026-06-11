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

const int N = 1e5 + 5;
int n, k, t;
unordered_set<int> st;
bool check(int x) {
    while (x) {
        int a = x % 10;
        if (st.count(a)) return false;
        x /= 10;
    }
    return true;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> t;
        st.insert(t);
    }
    int i = n;
    while (1) {
        if (check(i)) {
            cout << i << endl;
            exit(0);
        }
        ++i;
    }

    return 0;
}
