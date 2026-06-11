#include <stdio.h>
#include <string.h>
#include <deque>
#include <iostream>
using namespace std;
int main()
{
	deque<int> d;
	int n;
	int a;
	int flag = 0;
	cin >> n;
	while (cin >> a)
	{
		if (n % 2 == 0)
		{
			if (flag % 2 == 0) d.push_back(a);
			else d.push_front(a);
		}
		else
		{
			if (flag % 2 == 0) d.push_front(a);
			else d.push_back(a);
		}
		++flag;
	}
	auto it = d.begin();
	while (it != d.end())
	{
		cout << *it << " ";
		++it;
	}
}