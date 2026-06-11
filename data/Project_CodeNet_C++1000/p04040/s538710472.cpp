#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

typedef long long int ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

class Combination
{
public:
	Combination(long long int mod)
		:mod(mod)
	{}
	~Combination()
	{}

	void init(int n)
	{
		fact.resize(n);
		fact[0] = 1;
		for (int i = 1; i < n; ++i)
		{
			//! 階乗
			fact[i] = fact[i - 1] * i;
			fact[i] %= mod;
		}

		//! 階乗の逆元
		revFact.resize(n);
		revFact[n - 1] = powmod(fact[n - 1], mod - 2);
		for (int i = n - 2; i >= 0; --i)
		{
			revFact[i] = revFact[i + 1] * (i + 1);
			revFact[i] %= mod;
		}
	}

	long long int get(int a, int b)
	{
		return (((fact[a] * revFact[b]) % mod)*revFact[a - b]) % mod;
	}

private:

	long long int powmod(long long int a, long long int p)
	{
		long long int ans = 1;
		long long int mul = a;
		for (; p > 0; p >>= 1, mul = (mul*mul) % mod)
		{
			if ((p & 1) == 1) ans = (ans*mul) % mod;
		}
		return ans;
	}
	long long int mod;
	std::vector<long long int> fact;
	std::vector<long long int> revFact;
};

int main()
{
	int H, W;
	cin >> H >> W;
	int A, B;
	cin >> A >> B;

	Combination comb(MOD);
	comb.init(H + W);
	ll sum = 0;
	pii g(A, B);
	while (g.first < H && g.second < W)
	{
		int h = H - 1 - g.first;
		int w = W - 1 - g.second;

		ll first = comb.get(h + g.second, h);
		ll second = comb.get(g.first + w, w);
		sum += (first*second) % MOD;
		sum %= MOD;
		g.first++; g.second++;
	}

	cout << sum << endl;
	return 0;
}