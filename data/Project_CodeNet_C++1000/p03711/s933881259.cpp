#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	vector<int> Group1 = {1,3,5,7,8,10,12};
	vector<int> Group2 = {4,6,9,11};
	int Group3 = 2;
	int		a, b;
	int		cnt = 0;
	cin >> a >> b;
	for (auto &i : Group1)
	{
		if (i == a)
			cnt++;
		if (i == b)
			cnt++;
		if (cnt == 2)
			goto OUT;
	}
	cnt = 0;
	for (auto &i : Group2)
	{
		if (i == a)
			cnt++;
		if (i == b)
			cnt++;
		if (cnt == 2)
			goto OUT;
	}
	cnt = 0;
	if (Group3 == a)
		cnt++;
	if (Group3 == b)
		cnt++;
	OUT:
	cout << (cnt == 2 ? "Yes" : "No") << endl;
}