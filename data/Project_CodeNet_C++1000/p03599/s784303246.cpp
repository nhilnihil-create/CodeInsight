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
	for (int i= 0; i <b; i++)
	{
		ans *= a;
		ans %= AAA;
	}
	return ans;
}

int Sugar(int Maxsugar, int C, int D) {
	int s = Maxsugar;

	int ans = 0;
	for (int i = 0; i <= s / C; i++) {
		int tmp = (s - C * i) / D * D;
		tmp += C * i;
		ans = max(ans, tmp);
	}
	return ans;
}

int main() {
	int i, j, k;

	int N, M, K;

	int dp[3001] = { 0 };

	int A, B, C, D;
	int a, b, c, d;
	int E, F;

	cin >> A >> B >> C >> D;
	cin >> E >> F;
	double best=0;
	pairII bestPair = make_pair(100*A,0);
	rep(i, 0, 31) {
		rep(j, 0, 31) {
			int W = 100 * A* i +100 *  B * j;
			if (W == 0 || W > F)continue;

			int MaxSugar = min(W * E / 100, F - W);
			int S = Sugar(MaxSugar, C, D);
			if ((double)S / (S + W) > (double)bestPair.second / bestPair.first)
				bestPair = make_pair(S + W, S);
		}
	}
	cout << bestPair.first << " " << bestPair.second;
	return 0;
}