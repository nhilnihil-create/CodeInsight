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

	length = min(B, D) - max(A, C);

	cout << max(0, length) << endl;

	system("pause");
	return 0;
}