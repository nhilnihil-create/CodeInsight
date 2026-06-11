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

int p[400010];

int main(){
    int n, x;
    cin >> n >> x;
    if (x == 1 || x == 2*n-1) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, 2*n-1) p[i] = i+1;
    rep(i, 2*n-1) p[2*n-1+i] = i+1;

    int s = x - n + 1;
    if(s <= 0) s += 2*n-1;
    s--;
    cout << "Yes" << endl;
    for(int i = s; i < 2*n+s-1; i++) cout << p[i] << endl;

    return 0;
}
