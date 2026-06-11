
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
int func_check(int a, int b, int n)
{
	if (a + b == n)
	{
		return 1;
	}
	return 0;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	long long i, j, k;
	long long sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	long long w = tx - sx;
	long long h = ty - sy;
	string result;
	for (i = 0; i < h; i++)
		result += 'U';
	for (i = 0; i < w; i++)
		result += 'R';
	for (i = 0; i < h; i++)
		result += 'D';
	for (i = 0; i < w; i++)
		result += 'L';
	result += 'L';
	for (i = 0; i < h + 1; i++)
		result += 'U';
	for (i = 0; i < w + 1; i++)
		result += 'R';
	result += "DR";
	for (i = 0; i < h + 1; i++)
		result += 'D';
	for (i = 0; i < w + 1; i++)
		result += 'L';
	result += 'U';
	cout << result;
	return 0;
}