#include <bits/stdc++.h>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)

#define irrep(i,n) for(int i = (int)(n); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)

typedef long long ll;
typedef std::vector<char> v_char;
typedef std::vector<v_char > v2_char;
typedef std::vector<double> v_double;
typedef std::vector<v_double > v2_double;
typedef std::vector<int> v_int;
typedef std::vector<v_int > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<v_ll > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<v_string > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<v_bool > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std; 

int main(void)
{
    int n, a;
    cin >> n >> a;

    v_ll x(n); 
    irep(i, n) {
        cin >> x[i];
    }

    ll dp[n+1][n+1][n*a+100];

    irep(i, n+1) {
        irep(j, n+1) {
            lrep2(k, 0, n*a) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;

    irep(i, n) {
        irep(j, n) {
            lrep2(k, 0, n*a) {
                dp[i+1][j+1][k+x[i]] += dp[i][j][k];
                dp[i+1][j][k] += dp[i][j][k];
            }
        }
    }
    #if 0
    irep(i, n+1) {
        irep(j, n) {
            irep2(k, 0, n*a) {
                printf("dp[%d,%d,%d],%lu\n", i, j, k ,dp[i][j][k]);
            }
        }
    }
    #endif
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
            ans += dp[n][i][i*a];
    }
    cout << ans << endl;
    return 0;
}
/** atcoder **/
