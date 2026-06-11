#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<map>
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int main() {
	int N, f = 0, c = 0;
	cin >> N;
	vector<int> A(N);
	rep(i, 0, N)cin >> A[i];
	rep(i, 0, N - 1) {
		if (f == 0) {
			if (A[i] == A[i + 1])continue;
			else if (A[i] > A[i + 1])f = -1;
			else f = 1;
		}
		else if (A[i] != A[i + 1] && (A[i + 1] - A[i]) * f < 0) {
			f = 0;
			c++;
		}
	}
	printf("%d\n", c + 1);
	return 0;
}
