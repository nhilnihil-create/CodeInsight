#include <bits/stdc++.h>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int  i = 0; i < n; i++)
#define irep2(i,a,n) for(int i = (a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (a); i <= (long long)(n); i++)

typedef long long ll;
typedef std::vector<char> v_char;
typedef std::vector<double> v_double;
typedef std::vector<std::vector<double> > v2_double;
typedef std::vector<int> v_int;
typedef std::vector<std::vector<int> > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<std::vector<ll> > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<std::vector<std::string> > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<std::vector<bool> > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int dp[45][1005][1005];

int main(void)
{
    int n, ma, mb;
    cin >> n >> ma >> mb;

    v_int a(n), b(n), c(n);

    irep(i, n) {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }
    
    irep(i, 45) {
        irep(ca, 1005) {
            irep(cb, 1005) {
                dp[i][ca][cb] = INF;
            }
        }
    }
    
    dp[0][0][0] = 0;

    irep(i, n) {
        irep(ca, 1005) {
            irep(cb, 1005) {
                dp[i+1][ca][cb] = min(dp[i+1][ca][cb], dp[i][ca][cb]);
                if(ca < a[i] || cb < b[i]) { continue; }
                dp[i+1][ca][cb] = min(dp[i+1][ca][cb], dp[i][ca - a[i]][cb - b[i]] + c[i]);
            }
        }
    }
#if 0
    irep(i, n) {
        irep(ca, 40) {
            irep(cb, 40) {
                printf("i,%d,ca,%d,cb,%d,%d\n", i, ca, cb,dp[i][ca][cb]);
            }
        }
    }
#endif
    int ans = INF;
    irep2(ca, 1, 1000) {
        irep2(cb, 1, 1000) {
            if(ca*mb == cb*ma) { 
                ans = min(ans, dp[n][ca][cb]);
            }
        }
    }
    if(ans != INF) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
/** atcoder **/
