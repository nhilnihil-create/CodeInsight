#include <bits/stdc++.h>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)

#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
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
    ll a, b, c;
    cin >> a >> b >> c;

    ll ans = 0;

    while(a%2 == 0 && b % 2 == 0 && c % 2 == 0) {
        ll d = b/2 + c/2;
        ll e = a/2 + c/2;
        ll f = a/2 + b/2;
        ans++;

        if(d == e && e == f && d == f) {
            cout << -1 << endl;
            return 0;
        } else {
            a = d;
            b = e;
            c = f;
        }
    }
    cout << ans << endl;
    return 0;
}
/** tcoder **/
