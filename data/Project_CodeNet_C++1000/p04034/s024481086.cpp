#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N, M; cin >> N >> M;
    P box[N];//ball_num, isRed
    rep(i, N)
        box[i].first = 1, box[i].second = false;
    box[0].second = true;
    rep(i, M) {
        int x, y; cin >> x >> y; --x, --y;
        box[y].first += 1;
        box[x].first -= 1;
        if(box[x].second == true) {//xに赤い玉がある
            box[y].second = true;
            if(box[x].first == 0)
                box[x].second = false;
        }
    }
    int ans = 0;
    rep(i, N) {
        if(box[i].second) ++ans;
    }
    cout << ans << endl;
}
