#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector <int> v;
	for (int i = 0; i < 3; i++)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	if (v[0] == 5 && v[1] == 5 && v[2] == 7) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}
