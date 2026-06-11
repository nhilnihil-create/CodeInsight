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
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

int main() {
    int N, C, K; cin >> N >> C >> K;
    ll T[N]; rep(i, N) cin >> T[i];
    sort(T, T + N);
    int tmp = T[0];
    int cnt = 0;
    int ans = 0;
    rep(i, N) {
        if(tmp + K >= T[i]) {
            ++cnt;
            if(cnt >= C) {
                ++ans;
                cnt = 0;
                if(i + 1 < N) tmp = T[i + 1];
            }
        }else {
            if(cnt > 0) {
                ++ans;
                cnt = 1;
            }
            tmp = T[i];
        }
    }
    if(cnt > 0) ++ans;
    cout << ans << endl;
}
