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
 
const int N = 100 * 1000 + 5;
int a[N];
int ans = 0;
int n;

int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] == i + 1 && a[i - 1] == i)
		{
			ans++;
			swap(a[i], a[i - 1]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == i + 1)
		{
			ans++;
		}
	}
	cout << ans << endl;



}

























