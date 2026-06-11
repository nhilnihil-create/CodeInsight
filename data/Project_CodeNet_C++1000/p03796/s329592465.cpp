#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

ll INF = 1e9 + 7;

int main() {
	ll n;
	cin >> n;
	ll ans = 1;
	for (ll i = 1; i <= n; i++) {
		ans *= i;
		ans %= INF;
	}
	cout << ans << endl;
}