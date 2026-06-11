#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    ll x; cin >> x;
    if(x <= 6) {
        cout << 1 << endl;
    }else {
        ll ans = x / 11LL;
        ll tmp = x - 11LL * ans;
        if(tmp > 6) cout << 2 * ans + 2LL << endl;
        else if(tmp == 0) cout << 2 * ans << endl;
        else cout << 2 * ans + 1LL << endl;
    }
}
