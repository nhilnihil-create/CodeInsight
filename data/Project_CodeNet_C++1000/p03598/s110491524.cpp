#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int) (n); i++)
#define ll long long
#define scout cout << fixed << setprecision(20)
ll INF = 9e17;
ll mod = 1e9 + 7;

int main() {
	int n,k; cin >> n >> k;
	vector<int> x(n);
	rep(i,n) cin >> x[i];
	int ans = 0;
	rep(i,n) {
		ans += (min(x[i],abs(x[i]-k)))*2;
	}
	cout << ans << endl;
}