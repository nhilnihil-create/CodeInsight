#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int LOG = 20;

int n, len, q;
int a[MAXN];
int par[LOG][MAXN];
set <int> st;
map <int, int> mp;

void gen () {
    for (int i=n; i>=1; i--) {
        auto it = st.upper_bound(a[i] + len);
        if (it == st.begin()) {
            st.insert(a[i]);
            continue;
        }
        it--;
        par[0][i] = mp[*it];
        st.insert(a[i]);
    }
    for (int i=1; i<LOG; i++) {
        for (int j=1; j<=n; j++) {
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }
}

int kth (int x, int k) {
    int pot = 0;
    while (k > 0) {
        if (k & 1) x = par[pot][x];
        pot++;
        k /= 2;
    }
    if (x == 0) return n + 1;
    return x;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    cin >> len;
    gen();
    cin >> q;
    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int low = 1, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (kth(a, mid) >= b) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << low << '\n';
    }
    return 0;
}
