#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    ll N,M;
    cin >> N >> M;

    ll ans1 = 1;
    ll ans2 = 1;

    rep(i,N+M) {
        if (i%2==0) ans1 *= N-i/2, ans2 *= M-i/2;
        else ans1 *= M-i/2, ans2 *= N-i/2;
        ans1%=MOD;
        ans2%=MOD;
        
    }
    ll ans = ans1 + ans2;
    ans %= MOD;
    cout << ans << endl;
}
