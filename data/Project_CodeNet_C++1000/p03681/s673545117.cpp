#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define MOD 1000000007

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<P> vpi;


int main() {
    ll N,M,ans = 0,num = 0;
    cin >> N >> M;
    
    if(abs(N - M) > 1)
        ans = 0;
    else{
        ans = 1;
        rep1(i,N){
            ans *= i;
            ans %= MOD;
        }
        rep1(i,M){
            ans *= i;
            ans %= MOD;
        }
        if(abs(N - M) == 0)
            ans = (ans * 2) % MOD;
    }

    cout << ans;
    //printf("%.15lf", ans);
    cout << "\n";
    return 0;
}
