#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef string str;

const ll MAXN = 1e5 + 10;
const ll MOD = 1000000000000037;

ll n, a[MAXN], ps[MAXN];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, b;
	cin >> a >> b;
	if(a % 3 == b % 3) cout << (a == b ? "Brown" : "Alice") << '\n';
	else cout << (abs(a - b) < 2 ? "Brown" : "Alice") << '\n';
	return 0;
}
