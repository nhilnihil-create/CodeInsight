#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include<cmath>
#include<limits>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
using namespace std;


class LargeNumber {
private:
	bool is_prime[300000 + 13];// Up to 3e5 + 1
	vector<long long> Prime_table;
public:
	vector<long long> Eratosthenes(const long long N = 300007) { // return primes up to N
		for (int i = 0; i <= N; i++)
		{
			is_prime[i] = true;
		}
		for (int i = 2; i <= N; i++)
		{
			if (is_prime[i])
			{
				for (int j = 2 * i; j <= N; j += i)
				{
					is_prime[j] = false;
				}
				Prime_table.emplace_back(i);
			}
		}
		return Prime_table;
	}

	template<typename T>
	map<T, T> mFactorization(T N) const {
		map<T, T> mp;
		if (N == 1) {
			return mp;
		}

		for (int i = 0; i < Prime_table.size(); i++) {
			while (N % Prime_table[i] == 0) {
				mp[Prime_table[i]]++;
				N /= Prime_table[i];
			}
		}

		if (N > 1) mp[N]++;

		return mp;
	}

	bool isPrime(long long x) {
		if (x == 0 || x == 1) {
			return false;
		}
		return is_prime[x];
	}

	template<typename T>
	map<T, T> solve(T N, map<int, int>& mp) {
		if (N == 1) {
			return mp;
		}

		for (int i = 0; i < Prime_table.size(); i++) {
			while (N % Prime_table[i] == 0) {
				mp[Prime_table[i]]++;
				N /= Prime_table[i];
			}
		}

		if (N > 1) mp[N]++;

		return mp;
	}
};

template<typename T>
T modpow(T x, T n) {
	T res = 1;
	for (int i = 0; i < n; i++) {
		res *= x;
		res %= MOD;
	}
	return res;
}
int main() {
	LargeNumber Lg;
	const int M = 1005;
	Lg.Eratosthenes(M);
	map<int, int> mp_master;
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		Lg.solve(i,mp_master);
	}
	ll ans = 1;
	for (auto iter = mp_master.begin(); iter != mp_master.end(); iter++) {
		ans *= (iter->second + 1);
		ans %= MOD;
	}

	cout << ans << endl;
}