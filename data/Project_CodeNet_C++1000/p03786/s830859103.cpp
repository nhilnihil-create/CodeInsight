#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl

/*-- template --*/

int main() {
    int N; cin >> N;
    ll creatures[N];
    rep(i, N) cin >> creatures[i];
    sort(creatures, creatures + N);
    ll sum_creatures[N];
    sum_creatures[0] = creatures[0];
    rep(i, N - 1)sum_creatures[i + 1] = sum_creatures[i] + creatures[i + 1];
    if(creatures[1] <= 2 * creatures[0])
        sum_creatures[0] += creatures[1];
    int ans = 1;
    rep(i, N - 1) {
        if(creatures[N - i - 1] <= 2 * sum_creatures[N - i - 2]) {
            ++ans;
        }else {
            break;
        }
    }
    cout << ans << endl;
}
