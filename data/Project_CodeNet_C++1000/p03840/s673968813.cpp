#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<assert.h>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<complex>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int I, O, _, J, L;

signed main() {
    cin >> I >> O >> _ >> J >> L;
    int ans = 0;
    ans += O;
    O = 0;
    if (I && J && L && I % 2 + J % 2 + L % 2 >= 2) {
        ans += 3;
        --J, --L, --I;
    }
    ans += 2 * (J / 2);
    J -= J / 2;
    ans += 2 * (L / 2);
    L -= L / 2;

    ans += 2 * (I / 2);
    cout << ans << endl;
    return 0;
}
