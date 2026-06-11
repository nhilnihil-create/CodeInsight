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


int main(){
    int w, h, n;
    cin >> w >> h >> n;
    int xmax = w, xmin = 0;
    int ymax = h, ymin = 0;

    rep(i, n){
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) xmin = max(xmin, x);
        else if (a == 2) xmax = min(xmax, x);
        else if (a == 3) ymin = max(ymin, y);
        else if (a == 4) ymax = min(ymax, y);
    }

    cout << max(xmax-xmin, 0) * max(ymax-ymin, 0) << endl;


    return 0;
}
