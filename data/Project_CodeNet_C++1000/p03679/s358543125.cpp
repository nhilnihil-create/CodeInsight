#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define mp make_pair
#define EPS (int)1e-9
#define PI acos(-1)
#define endl '\n'
#define pb push_back
#define fi first
#define se second

using namespace std;
using ld = long double;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int mod = 1000000007;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll x, a, b;
	cin >> x >> a >> b;

	if(a >= b)
	{
		cout << "delicious" << endl;
		return 0;
	}
	if(b-a <= x)
	{
		cout << "safe" << endl;
		return 0;
	}

	cout << "dangerous" << endl;
	return 0;	
}