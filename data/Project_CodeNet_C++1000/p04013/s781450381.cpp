#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define PER(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define mk make_pair
#define S second
#define F first
typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
const int MAX = 55;
int N, K, a[MAX];
ll pd[MAX][MAX][MAX*MAX];
ll ans;

ll solve(int i, int k, int s) {
    if(s < 0 || k < 0) return 0;
    if(i == N && s|k) return 0;
    if(i == N) return 1;
    ll &ans = pd[i][k][s];
    if(ans != -1) return ans;
    return ans = solve(i+1, k-1, s-a[i]) + solve(i+1, k, s);
}

int main(int argc, char ** argv) {
    scanf("%d%d", &N, &K);
    rep(i, 0, N) scanf("%d", a+i);
    memset(pd, -1, sizeof pd);
    REP(i, 1, N) ans += solve(0, i, i*K);
    printf("%lld\n", ans);
	return 0;
}
