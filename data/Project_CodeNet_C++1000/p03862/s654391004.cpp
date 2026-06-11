#include<algorithm>
#include<cmath>
#include<climits>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
const ll MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{
	int N, x;
	cin >> N >> x;

	vll a(N);
	rep(i, N) cin >> a[i];

	ll count = 0;

	rep(i, N - 1)
	{
		int diff = a[i] + a[i + 1] - x;

		if (diff > 0)
		{
			//右側から先に引く
			if (a[i + 1] > diff)
			{
				a[i + 1] -= diff;
				count += diff;
				diff = 0;
			}
			else
			{
				diff -= a[i + 1];
				count += a[i + 1];
				a[i + 1] = 0;
			}

			//あまりは左側から引く
			if (diff > 0)
			{
				count += diff;
				a[i] -= diff;
				diff = 0;
			}
		}
	}

	cout << count << endl;

	return 0;
}