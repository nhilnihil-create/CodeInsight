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

int ans;
int main() {
	int k, s;
	cin >> k >> s;

	for(int x = 0; x <= k; x++) {
		for(int y = 0; y <= k; y++) {
			int z = s - x - y;
			if(z >= 0 && z <= k)
				ans++;
		}
	}
	cout << ans << endl;
    return 0;
}

