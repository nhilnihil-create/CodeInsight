#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    const int MOD = 1e9 + 7;
    ll ans = 1;
    int free = 0;
    rep(i, N) {
        int x;
        cin >> x;
        if (x < 2 * free + 1) {
            ans *= free + 1;
            ans %= MOD;
        } else {
            free++;
        }
    }
    while (free > 1) {
        (ans *= free--) %= MOD;
    }
    cout << ans << endl;
}
