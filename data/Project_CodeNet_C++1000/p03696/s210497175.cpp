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
#define Max(a,b) ((a) < (b) ? (b) : (a))
#define Min(a,b) ((a) > (b) ? (b) : (a))
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


int main() {
	int i, j, k;
	int N, M, K;

	string S;
	cin >> N >> S;

	int a, b;
	a = b = 0;
	int c = 0;
	rep(i, 0, N) {
		if (S[i] == '(') {
			c++;
		}
		else {
			if (c > 0)
				c--;
			else
				b++;

		}
	}
	a = c;
	rep(i, 0, b)
		cout << '(';

	cout << S;
	rep(i, 0, a)
		cout << ')';


	return 0;

}
