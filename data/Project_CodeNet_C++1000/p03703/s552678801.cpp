#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<long double, null_type, less<long double>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 200 * 1000 + 23;
const long double E = 1e-6;






int n, k;
ll ps[MAXN], ans;
long double tav;

int main() {
    ordered_set os;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> ps[i], ps[i] -= k - ps[i - 1];
    os.insert(0);
    for (int i = 1; i <= n; i++) {
        ans += os.order_of_key(ps[i] + 1);
        tav += E;
        os.insert(ps[i] + tav);
    }
    cout << ans;
    return 0;
}