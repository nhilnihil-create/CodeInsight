#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i > 0; i--)
#define FOR(i, n, m) for(int i = n; i < (int)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define PI 3.14159265358979

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;

    vector<ll> T(N);
    REP(i, N) cin >> T[i];

    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    if (!(T.front() <= A.front()) || !(T.back() >= A.back())) {
        PRINT(0);
        return 0;
    }

    vector<ll> v(N);
    v[0] = T.front();
    v.back() = A.back();
    REP(i, N-1) {
        if (T[i] < T[i+1]) {
            if(T[i+1] > A[i+1]) {
                PRINT(0);
                return 0;
            }
            v[i+1] = T[i+1];
        }
        if (A[i] > A[i+1]) {
            if (A[i] > T[i]) {
                PRINT(0);
                return 0;
            }
            v[i] = A[i];
        }
    }
    ll ans = 1;
    REP(i, N) {
        if (v[i] == 0) {
            ans *= min(T[i], A[i]);
            ans %= MOD;
        }
    }
    PRINT(ans);
    return 0;
}
