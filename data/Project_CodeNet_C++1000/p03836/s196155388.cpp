#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	for(int64 ii = 0;ii < tx - sx;ii++)
	{
		cout << 'R';
	}
	for(int64 ii = 0;ii < ty - sy;ii++)
	{
		cout << 'U';
	}
	for(int64 ii = 0;ii < tx - sx;ii++)
	{
		cout << 'L';
	}
	for(int64 ii = 0;ii < ty - sy;ii++)
	{
		cout << 'D';
	}
	cout << 'D';
	for(int64 ii = 0;ii <= tx - sx;ii++)
	{
		cout << 'R';
	}
	for(int64 ii = 0;ii <= ty - sy;ii++)
	{
		cout << 'U';
	}
	cout << "LU";
	for(int64 ii = 0;ii <= tx - sx;ii++)
	{
		cout << 'L';
	}
	for(int64 ii = 0;ii <= ty - sy;ii++)
	{
		cout << 'D';
	}
	cout << 'R' << endl;
	return 0;
}