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
    ll A[N];
    rep(i, N) cin >> A[i];
    ll sum = 0, ans = 0;
    rep(i, N) {
        if(A[i] == 0) {
            ans += sum / 2;
            sum = 0;
        } else {
            sum += A[i];
        }
    }
    ans += sum / 2;
    cout << ans << endl;
}
