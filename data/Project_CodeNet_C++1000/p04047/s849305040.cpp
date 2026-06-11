#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 2e5 + 5;
ll a[N];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        //freopen("VLJUM.INP", "r", stdin);
        //freopen("VLJUM.OUT", "w", stdout);
        ll n;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++) cin >> a[i];
        sort(a + 1, a + 2 * n + 1);
        ll ans = 0;
        for (int i = 1; i <= n; i++){
                ans = ans + min(a[(i - 1) * 2 + 1], a[(i - 1) * 2 + 2]);
        }
        cout << ans;
}

