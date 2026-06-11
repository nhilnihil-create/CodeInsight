/*
 * Author       : YangDavid
 * Created Time : 2019年07月12日 星期五 10时28分09秒
 */

#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, x;
ll solve(ll L, ll R) {
    if(L % R == 0) return 2LL * (L - R);
    return 2LL * L - R - (L % R) + solve(R, L % R);
}
int main() {
    cin >> n >> x;
    cout << x + solve(n, n - x) << endl;
    return 0;
}
