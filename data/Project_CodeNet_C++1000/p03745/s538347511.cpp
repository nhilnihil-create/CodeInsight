#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
#include <queue>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <map>
#include <functional>
#include <limits>
#include <set>
#include <stack>
#include <cctype>
#define rep(i,a,b) for((i)=a;i<(int)(b);i++)

#define AAA (1000000007) 


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pairII;


ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll powD(ll a, ll b) {
	ll ans = 1;
	a %= AAA;
	for (int i = 0; i < b; i++)
	{
		ans *= a;
		ans %= AAA;
	}
	return ans;
}


int main() {
	int i, j, k;

	int N, M, K;

	vector<int> A;

	cin >> N;
	rep(i, 0, N) {
		int a;
		cin >> a;
		A.push_back(a);
	}

	int type = 0;
	int ans = 0;
	rep(i,1,N) {
		if (type == 0) {
			if (A[i - 1] < A[i])
				type = 1;
			if (A[i - 1] > A[i])
				type = -1;
			if (A[i - 1] == A[i])
				type = 0;
		}
		else if (type == 1) {
			if (A[i - 1] <= A[i])
				continue;
			else {
				type = 0;
				ans++;
			}
		}
		else {
			if (A[i - 1] >= A[i])
				continue;
			else {
				type = 0;
				ans++;
			}
		}
	}
	cout << ans+1;
	return 0;
}