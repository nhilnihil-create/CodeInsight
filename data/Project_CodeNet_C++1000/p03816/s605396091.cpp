#include <iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<limits.h>

#define MOD 1000000007
#define DEBUG 0


using namespace std;

long long int modpow(long long int a, int n) {

	if (n == 0)return 1;
	if (n == 1) return a;

	long long int wk = modpow(a, n / 2);

	long long int ret = 0;
	if (n % 2 == 0) {
		ret = 1;
	}
	else {
		ret = a;
	}

	return (((ret * wk) % MOD) * wk) % MOD;

}

long long int gcd(long long int a, long long int b) {
	long long int tmp;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	long long int r = a % b;

	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

long long int lcm(long long int a, long long int b) {

	long long int wk_int;

	wk_int = (a * b) % MOD;
	
	long long int ret;

	ret = (wk_int * modpow(gcd(a, b), MOD - 2)) % MOD;

	return ret;

}

bool isPrime(int n) {
	if (n == 1)return false;
	if (n == 2)return true;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}

	return true;
}




int dis[10][10];






int main()
{

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());

	int daburi = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1])daburi++;
	}

	int delans = (daburi + 1) / 2;
	int ans = n - (2 * delans);

	cout << ans << endl;


	return 0;

}

