#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int al = a.length(), bl = b.length();
	
	if (al > bl)
	{
		cout << "GREATER";
		return 0;
	}
	if (al < bl)
	{
		cout << "LESS";
		return 0;
	}
	if (a.compare(b) == 0)
	{
		cout << "EQUAL";
		return 0;
	}

	for (int i = 0; i < al; i++)
	{
		if (a[0] < b[0])
		{
			cout << "LESS";
			return 0;
		}
		else if (a[0] > b[0])
		{
			cout << "GREATER";
			return 0;
		}
	};
}