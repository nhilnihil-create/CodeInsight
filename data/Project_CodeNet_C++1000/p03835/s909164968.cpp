#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int K, S;
	cin >> K >> S;

	int ans = 0;
	for (int x = 0; x <= K; ++x)
	{
		for (int y = 0; y <= K; ++y)
		{
			if ((S - x - y) <= K && (S - x - y) >= 0)
			{
				ans++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}