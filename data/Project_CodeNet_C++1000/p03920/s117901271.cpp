#include<iostream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>

using namespace std;

class Counting {
	unsigned long long p, n;
	vector<long long> invMemo, facMemo, facInvMemo;
public:
	Counting(unsigned long long nn, unsigned long long np) {
		p = np;
		n = nn;
		invMemo.resize(n + 1);
		facMemo.resize(n + 1);
		facInvMemo.resize(n + 1);
		facMemo[0] = 1;
		facMemo[1] = 1;
		facInvMemo[0] = 1;
		facInvMemo[1] = 1;
		invMemo[0] = 0;
		invMemo[1] = 1;
		for (unsigned long long i = 2; i <= n; i++) {
			invMemo[i] = p - (p / i)*invMemo[p%i] % p;
			facMemo[i] = (facMemo[i - 1] * i) % p;
			facInvMemo[i] = (facInvMemo[i - 1] * invMemo[i]) % p;
		}
	}
	unsigned long long fac(unsigned long long k) {
		return facMemo[k];
	}
	unsigned long long facInv(unsigned long long k) {
		return facInvMemo[k];
	}
	unsigned long long choose(unsigned long long n, unsigned long long k) {
		if (!(0 <= k && k <= n))
			return 0;
		return (((facMemo[n] * facInvMemo[k]) % p)*facMemo[n - k]) % p;
	}
	unsigned long long divide(unsigned long long a, unsigned long long b) {
		return (a * invMemo[b]) % p;
	}
	unsigned long long mod(unsigned long long a) {
		a %= p;
		if (a < 0) a += p;
		return a;
	}
	unsigned long long power(unsigned long long a, unsigned long long e) {
		unsigned long long ans = 1;
		for (; e > 0; e /= 2) {
			if (e % 2 != 0)
				ans = ans * a % p;
			a = a*a%p;
		}
		return ans;
	}
};

long long n;

int main() {
	cin >> n;
	double N;
	while (true)
	{
		N = -1 + sqrt(1 + 8 * n);
		cout << ceil(N / 2) << endl;
		n -= ceil(N / 2);
		if (n== 0)
			break;
	}

	//cin >> n;
	return 0;
}