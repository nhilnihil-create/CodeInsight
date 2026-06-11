#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i >= 0; i--)
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
    ll N, M;
    cin >> N >> M;
    vector<ll> tree(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        tree[a]++;
        tree[b]++;
    }
    REP(i, N) {
        if (tree[i] % 2 == 1) {
            PRINT("NO");
            return 0;
        }
    }
    PRINT("YES");
    return 0;
}
