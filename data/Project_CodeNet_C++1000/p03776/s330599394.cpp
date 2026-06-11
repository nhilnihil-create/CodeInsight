#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];
 
ll COM (long a,long b){
	if(a<b)return 0;
	long ans=1;
	for(long i=1;i<=b;i++)ans=ans*(a-i+1)/i;
	return ans;
}

ll v[100010];

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    rep(i, n) cin >> v[i];
    sort(v, v+n);
    reverse(v, v+n);
    long double ave = 0;
    rep(i, a) ave += v[i];
    ave /= a;

    int cnt = 0, pos = 0;
    rep(i, n) {
        if (v[i] == v[a-1]) {
            cnt++;
            if (i < a) pos++;
        }
    }
    ll ans = 0;
    if (pos == a) for(int i = a; i <= b; i++) ans += COM(cnt, i);
    else ans += COM(cnt, pos);

    cout << fixed << setprecision(10) << ave << endl;
    cout << ans << endl;

    return 0;
}
