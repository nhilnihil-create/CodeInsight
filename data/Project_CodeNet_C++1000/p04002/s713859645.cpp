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

P dir[9] = {mp(0, 0), mp(0, 1), mp(1, 0), mp(1, 1), mp(-1, 0), mp(0, -1), mp(-1, -1), mp(1, -1), mp(-1, 1)};

int main() {
    ll H, W, N;
    cin >> H >> W >> N;
    map<P, int> m;
    rep(i, N) {
        int a, b; cin >> a >> b;
        --a, --b;
        rep(j, 9) {
            int h = dir[j].first + a, w = dir[j].second + b;
            if(h < 1 || h >= H - 1 || w < 1 || w >= W - 1) continue;
            m[mp(h, w)]++;
        }
    }
    vector<ll>cnt(10, 0);
    ll sum = 0;
    for(auto itr = m.begin(); itr != m.end(); ++itr) {
        cnt[itr -> second]++;
        ++sum;
    }
    cnt[0] = (W - 2) * (H - 2) - sum;
    rep(i, 10)
        cout << cnt[i] << endl;
}
