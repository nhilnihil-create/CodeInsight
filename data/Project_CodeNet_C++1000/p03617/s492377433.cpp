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
    ll Q, H, S, L2; cin >> Q >> H >> S >> L2;
    ll L1 = min(min(Q * 4, H * 2), min(S, Q * 2 + H));
    ll N; cin >> N;
    if(N % 2 == 0) {
        cout << min(L1 * N, L2 * N / 2) << endl;
    }else {
        cout << min(L1 * N, (L2 * int(N / 2)) + L1) << endl;
    }
}
