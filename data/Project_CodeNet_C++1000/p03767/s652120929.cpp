#include<iostream>
#include<vector>
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
    int N; cin >> N;
    int a[3 * N];
    rep(i, 3 * N) {
        cin >> a[i];
    }
    sort(a, a + 3 * N, greater<int>());
    ll ans = 0;
    int count = 0;
    for(int i = 1; count != N; i += 2) {
        ans += a[i];
        ++count;
    }
    cout << ans << endl;
}
