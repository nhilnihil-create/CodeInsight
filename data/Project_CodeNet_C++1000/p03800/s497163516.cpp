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
#define MOD 1000000007
#define vl vector<ll>

vector<ll> dx = {-1, 1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


void check(vector<bool> &v, ll N, string S) {
	FOR(i, 1, N-1) {
		if(S[i] == 'o') {
			if (v[i]) v[i+1] = v[i-1];
			else v[i+1] = !v[i-1];
		} else {
			if (v[i]) v[i+1] = !v[i-1];
			else v[i+1] = v[i-1];
		}
	}
	if (!(!((S[N-1] == 'o') ^ v[N-1]) ^ (v[N-2] == v[0]))) {
		if (!(!((S[0] == 'o') ^ v[0]) ^ (v[N-1] == v[1]))) {
			REP(i, N) {
				if (v[i]) cout << "S";
				else cout << "W";
			}
			cout << endl;
			exit(0);
		}
	}
}

int main()
{
	ll N;
	string S;
	cin >> N >> S;
	vector<bool> v(N);
	v[0] = true;
	v[1] = true;
	check(v,N,S);
	v[0] = false;
	v[1] = true;
	check(v,N,S);
	v[0] = true;
	v[1] = false;
	check(v,N,S);
	v[0] = false;
	v[1] = false;
	check(v,N,S);
	PRINT(-1);
	return 0;
}
