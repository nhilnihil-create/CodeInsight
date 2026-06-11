#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int a[100010];

int main(){
    int n;
    cin >> n;
    int m = n, k = 0;
    rep(i, n){
        cin >> a[i];
        m = min(m, a[i]);
        k = max(k, a[i]);
    }
    if (k > m+1) {
        cout << "No" << endl;
    }
    else if (k == m){
        if (k == n-1 || 2*k <= n) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else {
        int x = 0;
        rep(i, n) if (a[i] == m) x++;
        if (x < k && 2*(k-x) <= n-x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
