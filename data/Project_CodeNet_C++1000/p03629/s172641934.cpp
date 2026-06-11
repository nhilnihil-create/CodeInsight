#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, dp[MX], sig[MX][30];
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = s.size();

	forn (i, 30) sig[n][i] = n;
	forn (i, 30) sig[n + 1][i] = n + 1;

	for (int i = n - 1; i >= 0; i--) {
		forn (j, 30) sig[i][j] = sig[i + 1][j];
		sig[i][s[i] - 'a'] = i;
	}

	for (int i = n; i >= 0; i--) {
		dp[i] = n;
		for (int j = 'a'; j <= 'z'; j++)
			dp[i] = min(dp[i], dp[sig[i][j - 'a'] + 1] + 1);
	}

	for (int i = 0; i <= n;) {
		for (int j = 'a'; j <= 'z'; j++)
			if (dp[i] == dp[sig[i][j - 'a'] + 1] + 1) {
				cout << char(j);
				i = sig[i][j - 'a'] + 1;
				break;
			}
	}

	cout << endl;

	return 0;
}
