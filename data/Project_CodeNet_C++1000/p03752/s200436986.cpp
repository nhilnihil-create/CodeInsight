#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
const LL MOD=1000000007ll;
const LL INF=2000000000ll;

long power(long a,long b){return b?power(a*a%MOD,b/2)*(b%2?a:1)%MOD:1;}
long comb(int N,int K)
{
	long x=1,y=1;
	for(int i=1;i<=K;i++)
	{
		x=x*(N-i+1)%MOD;
		y=y*i%MOD;
	}
	return x*power(y,MOD-2)%MOD;
}

long hcomb(int N, int K){
    return comb(N+K-1, N-1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);

    int N, K;
    cin >> N >> K;
    VI a(N);
    REP(i,N) cin >> a[i];

    LL ans = INF*INF;
    REP(bit, 1<<N){
        if (__builtin_popcount(bit) >= K && bit & (1<<0)){
            LL M = a[0], cost = 0;
            FOR(i,1,N){
                if (bit & (1<<i)){
                    if (a[i] <= M) {
                        M++;
                        cost += M-a[i];
                    }
                    else {
                        M = a[i];
                    }
                }
                else {
                    M = max(M, (LL)a[i]);
                }
            }
            ans = min(ans, cost);
        }
    }

    cout << ans << endl;
}