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
	int t[101] = { 0 };
	int tt[101] = { 0 };
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		t[i+1] = x;
		tt[i+1] = x;
	}
	int m;
	cin >> m;
	for(int i = 1; i <= m; i++) {
		int p, x;
		cin >> p >> x;
		t[p] = x;
		cout << accumulate(t, t + 101, 0) << endl;
		for(int i = 0; i < 101; i++)
			t[i] = tt[i];
	}
    return 0;
}

