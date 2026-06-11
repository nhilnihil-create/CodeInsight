#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	ll A, B, C;
	cin >> A >> B >> C;

	bool find = false;
	if (C % GCD(A, B) == 0)
	{
		find = true;
	}

	
	if (find) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}