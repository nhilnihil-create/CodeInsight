//Be Name Khoda, Besmellah Rahmane Rahim, In The Name Of God;
//#include<bits/stdc++.h>
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
#include <stdio.h>
#include <string.h>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>

using namespace std;
 
const int N = 1e5 + 5;
int n, ind;
int a[N];
 
int main() 
{
	cin >> n;
 
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (n == 1) 
	{
		if (a[0] % 2 == 1)
		{
			cout << "Second" << endl;
		}
		else
		{
			cout << "First" << endl; 
		}	
		return 0;
	}
	sort(a, a + n);
	reverse(a, a + n);
	if (a[0] == 1) 
	{
		if (n % 2 == 1)
		{
			cout << "Second" << endl; 
		}
		else
		{
			cout << "First" << endl; 
		}
		return 0;
	}
	ind = n;
	for (int i = 1; i < n; i++) 
	{
		if (a[i - 1] >= i && a[i] <= i) 
		{
			ind = i;
			break;
		}
	}
	ind--;
	if ((a[ind] - ind) % 2 == 0) 
	{
		cout << "First" << endl;
		return 0;
	}
	int cnt = 0;
	int tmp = ind + 1;
	while (tmp < n && a[tmp] == ind + 1) 
	{
		tmp++;
		cnt++;
	}
	if (cnt % 2 == 1) 
	{
		cout << "First" << endl;
	}
	else
	{
		cout << "Second" << endl;
	}
}
