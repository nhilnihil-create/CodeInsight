#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define dump(x) cout << (x) << endl
#define LMAX 9223372036854775807LL
#define LMIN -9223372036854775807LL
using ll = int64_t;
template<typename T>
using vec = vector<T>;
using P = pair<ll, ll>;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//ll pas[51][52];

bool dp[5002][5002] = {};

signed main(){
	IOS;
	ll n, k;
	cin >> n >> k;
    vec<ll> a(n + 1);   
    ll sum = 0;
    REP(i,n){
        cin >> a[i];
        sum += a[i];
    }
    a[n] = 0;
    if(sum < k){
        dump(n);
        return 0;
    }
    sort(ALL(a),greater<ll>());
    ll left = 0, right = n;
    ll mid;
    while(right - left > 1){
        Fill(dp,false);
        dp[0][0] = true;
        mid = (right + left) / 2;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < k;j++){
                if(i == mid)dp[i + 1][j] = dp[i][j];
                else {
                    dp[i + 1][j] = dp[i][j];
                    if(j >= a[i])dp[i + 1][j] |= dp[i][j - a[i]];
                }
            }
        }
        bool ok = false;
        for(int j = max(k - a[mid],(ll)0);j < k;j++)if(dp[n][j])ok = true;
        if(ok)left = mid;
        else right = mid;
    }
    left++;
    dump(n - left);
}