#include <cstdlib>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	int N,K;
	ll ret;
	cin >> N >> K;

	
	ret = K;
	if (N > 2)
	{
		rep(i, (N - 1))
		{
			ret *= (K - 1);
		}
	}

	cout << ret << endl;
	return 0;
}