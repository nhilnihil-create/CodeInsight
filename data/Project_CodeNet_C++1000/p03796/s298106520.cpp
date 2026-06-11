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
	int N;
	ll modi = 1e9 + 7;
	ll power = 1;
	cin >> N;
	
	rep(i, N)
	{
		power *= (i + 1);
		power = power % modi;
	}
	
	cout << power << endl;

	return 0;
}