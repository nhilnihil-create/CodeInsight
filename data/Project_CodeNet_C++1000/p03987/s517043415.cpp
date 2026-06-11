#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
 
int main() {
    int n;
    cin >> n;

    vector<int> a(n), ra(n+1);
    rep(i, n) {
        cin >> a[i];
        ra[a[i]] = i;
    }

    set<int> st;
    st.insert(-1);  st.insert(n);

    ll ans = 0;
    for(int d = 1; d <= n; d++) {
        int i = ra[d];
        auto it = st.lower_bound(i);
        int r = *it;
        it--;
        int l = *it;
        ans += (ll)d*(i-l)*(r-i);
        st.insert(i);
    }
    
    cout << ans << endl;
    return 0;
}