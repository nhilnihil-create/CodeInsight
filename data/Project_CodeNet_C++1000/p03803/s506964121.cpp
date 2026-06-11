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

#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 aa, bb;
	cin >> aa >> bb;
	if(aa == bb)
	{
		puts("Draw");
	}
	else if(aa == 1)
	{
		puts("Alice");
	}
	else if(bb == 1)
	{
		puts("Bob");
	}
	else if(aa > bb)
	{
		puts("Alice");
	}
	else
	{
		puts("Bob");
	}
	return 0;
}
