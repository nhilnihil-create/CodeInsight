#include <iostream>
#include <iomanip>
#include<math.h>
#include<list>
#include <algorithm>
#include<set>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include <numeric>
#include <queue>
#include <sstream>
#include <bitset>
#include<stack>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using sll = set<long long>;

template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
map<T, T> getPrimeFactor(T n) {
	map<T, T> res;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			res[i] ++;
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

template<typename T>
bool IsPrimeNumber(T num)
{
	if (num <= 2) return true;
	else if (num % 2 == 0) return false;

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}


#define in(x) cin >> x
#define out(x) cout << x
#define outn(x) cout << x << '\n'
#define outs(x) cout << x << ' '
#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)

int main() {
	ll N, M, a, b, c;
	std::cin >> N >> M;
	vector<vll> t(N + 1, vll(N + 1, 1e9));
	vector<vector<vector<pair<ll, ll>>>> e(N + 1, vector<vector<pair<ll, ll>>>(N + 1));
	repeq(i, 1, N) {
		t[i][i] = 0;
	}

	rep(i, 0, M) {
		std::cin >> a >> b >> c;
		t[a][b] = c;
		t[b][a] = c;
		e[min(a, b)][max(a, b)].push_back(make_pair(min(a, b), max(a, b)));
	}

	repeq(k, 1, N) {
		repeq(i, 1, N) {
			repeq(j, 1, N) {
				if (t[i][j] > t[i][k] + t[k][j]) {
					t[i][j] = t[i][k] + t[k][j];

					e[i][j] = {};
					std::copy(e[i][k].begin(), e[i][k].end(), std::back_inserter(e[i][j]));
					std::copy(e[k][j].begin(), e[k][j].end(), std::back_inserter(e[i][j]));
				}
			}
		}
	}

	ll ans = M;
	map<ll, map<ll, bool>> dic;
	repeq(i, 1, N) {
		repeq(j, 1, N) {
			rep(k, 0, e[i][j].size()) {
				if (!dic[e[i][j][k].first][e[i][j][k].second]) {
					dic[e[i][j][k].first][e[i][j][k].second] = true;
					ans--;
				}
			}
		}
	}

	std::cout << ans << endl;

	return 0;

}
