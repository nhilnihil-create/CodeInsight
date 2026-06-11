#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional> 
#include <iomanip>
#include <unordered_map>
#include <memory.h>
#include <cstring>
#include <fstream>

using namespace std;

long long int psum[100001];
bool possible[100001];
vector <long long int> v;
long long int t;
int n;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	memset(psum, 0, sizeof(psum));
	memset(possible, false, sizeof(possible));

	for (int i = 1; i <= n; i++)
	{
		psum[i] = psum[i - 1] + v[i - 1];
	}

	possible[n] = true;
	for (int i = n - 1; i >= 1; i--)
	{
		if (2 * psum[i] < v[i])
		{
			possible[i] = false;
			break;
		}
		possible[i] = true;
	}

	int res = 0;
	for (int i = n; i >= 0; i--)
	{
		if (possible[i] == false)
		{
			break;
		}
		res++;
	}

	cout << res << '\n';

	return 0;
}