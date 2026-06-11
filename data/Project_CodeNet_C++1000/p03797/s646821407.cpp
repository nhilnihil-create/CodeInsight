#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define INF 1000000007

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<P> vpi;


int main() {
    ll N,M,ans = 0;
    cin >> N >> M;

    if(N >= M/2)
        ans = M/2;
    else{
        ans = N;
        M -= 2*N;
        ans += M/4;
    }

    cout << ans;
    //printf("%.15lf", ans);
    cout << "\n";
    return 0;
}
