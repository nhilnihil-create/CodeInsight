#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include <iomanip>

using namespace std;

const long long N = 100 * 1000 + 5;
long long n;
long long a, b;
long long damage = 0;
long long ans = 0;
long long monster[N];

bool isval(long long k)
{
	long long cnt = 0;
	for (long long i = 0; i < n; i++)
	{
		long long x = monster[i];
		x -= k * b;
		if (x <= 0)
			continue;
		cnt += (x / (a - b)) + bool(x % (a - b));
	}
	return cnt <= k;
}

long long bsearch()
{
	long long down = 0;
	long long up = 1000 * 1000 * 1000 + 5;
	while (up - down > 1)
	{
		long long md = (up + down) / 2;
		if (isval(md))
		{
			up = md;
		}
		else
		{
			down = md;
		}
	}
	return up;
}
 
 
int main() 
{
	cin >> n >> a >> b;
	for (long long i = 0; i < n; i++)
	{
		cin >> monster[i];
	}
	cout << bsearch();

}

























