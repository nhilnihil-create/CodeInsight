#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    ll blackCnt = 0;
    string ans;
    ans = "No";
    rep(ni, N + 1){
        rep(mi, M + 1){
            blackCnt = (ll)ni * M + mi * N - 2 * ni * mi;
            if(blackCnt == K){
                ans = "Yes";
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}