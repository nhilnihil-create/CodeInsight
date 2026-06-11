#include<iostream>
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

using namespace std;

const long long N = 1000ll * 1000 * 1000 * 1000 + 5;
long long cnt = -1;

vector <int> ans;

int main() 
{
	long long n;
	cin >> n;
	for (int i = 1; i <= 100; i++) 
	{
		ans.push_back(i);
	}
	for (int i = 0; i <= 100; i++) 
	{
		cnt++;
		if (n >= (1ll << i)) 
		{
			n -= (1ll << i);
		}
		else 
		{
			break;
		}
	}
	for (int i = 0; i < cnt; i++) 
	{
		if ((n >> i) % 2) 
		{
			ans.push_back(100 - i);
		}
		ans.push_back(i + 1);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) 
	{
		cout << ans[i] << " ";
	}
}

