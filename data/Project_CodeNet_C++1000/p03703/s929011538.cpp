#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define F first
#define S second
#define int long long
#define pii pair<int, int>
#define ins insert
#define sz size() 

using namespace std;

template<typename T>
using ordered_set = __gnu_pbds::tree<T,__gnu_pbds::null_type,std::less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

ordered_set < pii > st;
const int maxn = 2e5+5;
int n, k, ans, a[maxn];

void Speed() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

main(){
    Speed();
    cin >> n >> k;
    for(int i = 1; i <= n; ++ i) {
        cin >> a[i];
        a[i] -= k;
        a[i] += a[i - 1];
    }
    for(int i = 0; i <= n; ++ i) {
        int cnt = st.order_of_key({a[i] + 1, -1});
        ans += cnt;
        st.ins({a[i], i});
    }
    cout << ans;
}


