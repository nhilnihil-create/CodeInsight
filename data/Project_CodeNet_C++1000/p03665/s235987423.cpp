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

	int P;
	int A[50];

	ll a = 0, b = 0;
	cin >> N >> P;
	rep(i, 0, N) {
		cin >> A[i];
		if (A[i] % 2 == 0) {
			a++;
		}
		else {
			b++;
		}
	}
	ll tmp = 1;
	ll ans = 0;
	if (P == 0) {
		j = 0;
	}
	else {
		j = 1;
	}
		
	while (j <= b) {
	
		if (j != 0)
			tmp *= max((ll)1, (b - j +1));
		tmp /= max(1, j);
		ans += tmp;
		j++;
		tmp *= max((ll)1,(b - j+1));
		tmp /= j;
		j++;
	}

	ans *= pow(2, a);
	cout << ans;



	return 0;
}