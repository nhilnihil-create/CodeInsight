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


int num[100010];
bool red[100010];

int main(){
    int n, m;
    cin >> n >> m;

    rep(i, 100010) num[i] = 1;
    red[0] = 1;

    rep(i, m){
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (red[x] && num[x] > 1) red[y] = 1;
        else if (red[x] && num[x] == 1) red[x] = 0, red[y] = 1;
        num[x]--, num[y]++;
    }

    int ans = 0;
    rep(i, n) if (red[i]) ans++;
    cout << ans << endl;
    
    return 0;
}
