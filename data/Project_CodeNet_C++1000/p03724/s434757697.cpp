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

int c[100010];
int main(){
    int n, m;
    cin >> n >> m;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        c[a]++, c[b]++;
    }
    rep(i, n+1){
        if (c[i] % 2 != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
