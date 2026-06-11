#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void ARC072D()
{
	ull X, Y;
	cin >> X >> Y;
	if (X > Y)
	{
		swap(X, Y);
	}
	bool isA = Y - X >= 2;

	if (isA)
	{
		cout << "Alice" << endl;
		return;
	}
	else
	{
		cout << "Brown" << endl;
		return;
	}
}
int main()
{
	ARC072D();
	return 0;
}