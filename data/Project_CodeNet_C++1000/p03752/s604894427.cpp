#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <complex>
#include <ctime>


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef int itn;
const ll LINF = 1e18;
const int INF = 1e9;

//マクロ定義
#define vvint(vec,n,m,l) vector<vector<int>> vec(n, vector<int>(m,l));	// lで初期化
#define vvll(vec,n,m,l) vector<vector<ll>> vec(n,vector<ll>(m,l));
#define vint vector<int>
#define pint pair<int,int>
#define rep(i,a) for(int i=0;i<(a);i++)
#define all(x) (x).begin(),(x).end()
#define debug system("pause")				//デバッグ用
#define ret return 0

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using Graph = vector<vector<ll>>;

#define ketasitei setprecision(15) //15桁表示

const ll MOD = 1000000007;
const double PI = 3.1415926535897932;



int main(void)

{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << ketasitei;

	ll n,k;
	cin >> n >> k;
	vector<ll> a(n);
	vector<ll> h(n,0);
	
	rep(i, n)
	{
		cin >> a[i];
	}
	rep(i, n - 1)
	{
		h[i + 1] = max(a[i + 1], h[i]);
	}

	ll bit = (1LL << n) - 1LL;

	ll now = 0;
	ll sum = 0;
	rep(i, n)
	{
		if (now < a[i])
		{
			sum++;
			now = a[i];
		}
	}

	if (sum == k)
	{
		cout << 0 << endl;
		ret;
	}
	sum = 0;
	now = 0;
	ll ans = LINF;


	while (bit)
	{
		vector<ll> tal(n);
		rep(i, n)
			tal[i] = a[i];

		ll tmp = bit;
		now = 0;
		sum = 0;
		ll point = 0;
		while (tmp)
		{
			if (tmp & 1)
			{
				if (a[point] <= now)
				{
					sum += now - a[point] + 1;
					now++;
					tal[point] = now;
				}
			}

			tmp >>= 1;
			now = max(now, a[point]);
			point++;
		}

		now = 0;
		ll ok = 0;
		rep(i, n)
		{
			if (tal[i] > now)
			{
				ok++;
				now = tal[i];
			}
		}
		if (ok >= k)
		{
			ans = min(ans, sum);
		}
		bit--;
	}



	cout << ans << endl;
	return 0;
}