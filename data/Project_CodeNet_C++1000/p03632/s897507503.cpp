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
	int A, B, C, D;
	int length = 0;

	cin >> A >> B >> C >> D;

	if (B >= C)
	{ 
		length = min(B, D) - max(A, C);
	}

	if (length < 0) {
		length = 0;
	}

	cout << length << endl;
	return 0;
}