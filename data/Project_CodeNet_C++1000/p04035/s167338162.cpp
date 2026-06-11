#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(ll i = 0LL; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n-1; i >= 0LL; i--)
#define FOR(i, n, m) for(ll i = n; i < (ll)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define INFD 1e18
#define PI 3.14159265358979
// #define MOD 1000000007
#define MOD 998244353
#define VL vector<ll>

vector<ll> dx = {-1, 1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

vector<ll> dx8 = {-1, -1, -1,  0, 0,  1, 1, 1};
vector<ll> dy8 = {-1,  0,  1, -1, 1, -1, 0, 1};

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }



int main()
{
	ll N, L;
	cin >> N >> L;

	vector<ll> A(N);
	REP(i, N) cin >> A[i];
	vector<ll> ans;
	REP(i, N-1) {
		if (A[i] + A[i+1] >= L) {
			PRINT("Possible");
			ans.push_back(i+1);
			REPR(j, i) {
				ans.push_back(j+1);
			}
			FOR(j, i+1, N-1) {
				ans.push_back(j+1);
			}
			REPR(i, N-1) {
				PRINT(ans[i]);
			}
			return 0;
		}
	}
	PRINT("Impossible");
	return 0;
}
