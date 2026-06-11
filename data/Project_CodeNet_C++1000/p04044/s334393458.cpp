#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
	int n, l; cin >> n >> l; cin.ignore();
	vector<string> a;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		getline(cin, tmp);
		a.push_back(tmp);
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << "\n";
	return 0;
}