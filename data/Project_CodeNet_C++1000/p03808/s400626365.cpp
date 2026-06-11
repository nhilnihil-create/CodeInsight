#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<set>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll, ll> pll;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
#define MOD 1000000007
#define ARRAY_MAX 100005

const ll INF = 1e9 + 7;

int main() {

	ll n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	bool flag = true;

	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	ll md = n * (n + 1) / 2;
	if ((sum%md) != 0) {
		cout << "NO" << endl;
		return 0;
	}
	sum /= md;//操作回数

	for (ll i = 0; i < n; i++)
	{
		ll tmp = a[(i + 1) % n] - a[i];
		tmp -= sum;
		flag &= (tmp <= 0LL && (tmp % n == 0));
		
	}

	if (flag) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}
