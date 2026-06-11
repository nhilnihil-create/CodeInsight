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
#define max(a,b) ((a) < (b) ? (b) : (a))
#define min(a,b) ((a) > (b) ? (b) : (a))
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

//Xの点の値をSに足して、次の方向を返す
pairII func(int A[11][11], pairII X, pairII D, string *S) {
	S->push_back(A[X.first][X.second] + '0');

	pairII nextX = make_pair(X.first + D.first, X.second + D.second);
	if (A[nextX.first][nextX.second] != -1) {
		return D;
	}
	//X軸反転
	if (A[nextX.first - D.first][nextX.second] != -1) {
		return make_pair(-D.first, D.second);
	}
	//Y軸反転
	else if (A[nextX.first][nextX.second - D.second] != -1) {
		return make_pair(D.first, -D.second);
	}
	//角
	else {
		return make_pair(-D.first, -D.second);
	}
}

int main() {
	int i, j, k;
	//ll N, M, K;
	int N, M, K;

	vector<int> A;
	ll S[100001];

	cin >> N;

	rep(i, 0, N) {
		int a;
		cin >> a;
		A.push_back(a);
	}

	sort(A.begin(), A.end());
	S[0] = A[0];
	rep(i, 1, N-1) {
		S[i] = S[i - 1] + A[i];
	}

	ll ans = 0;
	rep(i, 0, N - 1) {
		if (S[i] * 2 >= A[i + 1]) {
			ans++;
		}
		else {
			ans = 0;
		}


	}
	cout << ans + 1;
	return 0;

}
