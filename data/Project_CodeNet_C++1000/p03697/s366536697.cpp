#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl '\n'
#define ll long long
#define ld long double
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mod (ll) (1e9 + 7)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(), v.end()
#define dvec(v) for(auto i: v) cout<< i<< " "; cout<< '\n';
#define gcd(a,b) __gcd(a, b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define darr(a,n) for(int i=0; i<n;i++) cout<< a[i]<< " "; cout<< '\n';
#define what_is(x) cerr<< #x<< " : "<< x<< '\n';


int32_t main() {
	fast;
	int a, b;
	cin >> a >> b;
	if (a + b > 9) {
		cout << "error" << endl;
	}
	else {
		cout << a + b << endl;
	}

	return 0;
}
