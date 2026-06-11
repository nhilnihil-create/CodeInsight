#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <thread>
#include <atomic>
#include <mutex>
#include <future>
#define int long long
#define endre getchar();getchar();return 0
#define INF 1000000007
using namespace std;
bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return (y, x%y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int kai(int n) {
	if (n == 0)return 1;
	return (kai(n - 1)*n) % INF;
}
int mod_pow(int x, int y, int mod) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x%mod;
		}
		x = x * x%mod;
		y >>= 1;
	}
	return res;
}
int mystoi(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		cnt += (int)(s[i] - '0') * pow(10, s.size() - i - 1);
	}
	return cnt;
}
int n;
signed main() {
	cin >> n;
	int cnt = 0, memo;
	for (int i = 1;; i++) {
		cnt += i;
		if (n <= cnt) {
			memo = i;
			break;
		}
	}
	for (int i = memo; i >= 1; i--) {
		if (i <= n) {
			n -= i;
			cout << i << endl;
		}
		if (!n)break;
	}
	endre;
}
