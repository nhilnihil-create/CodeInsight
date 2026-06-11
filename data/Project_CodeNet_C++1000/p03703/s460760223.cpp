//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef long long ijt;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;

//const long long INF = 1LL << 55;

#define itn int
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
#define rrep(i,n) for(int i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }

#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
template<typename T> // T: type of cost
struct BIT {
	int n;
	vector<T> d;
	BIT(int n = 0) :n(n), d(n + 1) {}
	void add(int i, T x = 1) {
		for (i++; i <= n; i += i & -i) {
			d[i] += x;
		}
	}
	T sum(int i) {
		T x = 0;
		for (i++; i; i -= i & -i) {
			x += d[i];
		}
		return x;
	}

	long long inversion(vector<T> a) {
		long long ans = 0;
		for (int j = 0; j < a.size(); j++) {
			ans += sum(a[j]);
			add(a[j], 1);
		}
		return ans;
	}
};
ll n, k;
ll a[200020];

int main(void) {
	cin >> n >> k;
	vector<ll> c(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] -= k;
		c[i + 1] += c[i] + a[i];
	}
	if (n == 1) {
		if (a[0] >= 0) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
		return 0;
	}
	//cを座標圧縮する
	vector<ll> b(n+1);
	for (int i = 0; i < n+1; i++)
	{
		b[i] = c[i];
	}
	sort(all(b));
	UNIQUE(b);
	for (int i = 0; i < n+1; i++)
	{
		c[i] = lower_bound(all(b), c[i]) - b.begin() + 1;
	}
	
	BIT<ll> bt(200020);
	cout << bt.inversion(c) << endl;
	return 0;
}