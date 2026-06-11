#include <bits/stdc++.h>
using namespace std;
#define ar array
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const ll mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x = 0;
	int ans = 0;
	for(char c : s) {
		if(c == 'I') ++x;
		else x--;
		ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}

