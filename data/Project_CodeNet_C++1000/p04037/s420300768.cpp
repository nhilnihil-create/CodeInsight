#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100100;
int v[maxn];
int n;
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> v[i];
	sort(v + 1, v + n + 1);
	int cnt = 0, a = 0;
	int p = 1;
	for(int i = n; i >= 1; i --)
	{
		while(v[p] <= a)
			p ++;
		if(p > i)
		{
			cout << "First" << endl;
			return 0;
		}
		if(v[p] == v[i])
		{
			if((v[i] - a + i - p) & 1)
				cout << "Second" << endl;
			else
				cout << "First" << endl;
			return 0;
		}
		if(v[p] == v[i - 1] && v[p] == a + 1)
		{
			if(((i - p) & 1) | ((v[i] - a - 1) & 1))
				cout << "First" << endl;
			else
				cout << "Second" << endl;
			return 0;
		}
		cnt += 2;
		a ++;
	}
	return 0;
}
/*
5
2 2 4 1 3 
*/