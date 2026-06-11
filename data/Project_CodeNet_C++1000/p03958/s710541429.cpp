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



ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int Get(string S) {
	int sum = 0;
	for (int i = 0; i < S.size() - 1; ++i) {
		if (S[i] == 'A' && S[i + 1] == 'B') {
			sum++;
		}
	}
	return sum;
}
int main() {
	int i, j, k;
	//ll N, M, K;
	int N, M, K;

	int T;
	cin >> K >> T;
	priority_queue<int> A;

	rep(i, 0, T) {
		int a;
		cin >> a;
		A.push(a);
	}
	int x = A.top();
	A.pop();
	while (!A.empty()) {
		int y = A.top();
		A.pop();
		if (x > y) {
			x -= y;
			continue;
		}
		y -= x;
		x = y;

	}
	if (x > 0) {
		cout << x - 1;

	}
	else
		cout << 0;
	return 0;

}
