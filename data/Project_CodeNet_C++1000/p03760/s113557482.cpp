#include<bits/stdc++.h>
using namespace std;
int main() {
	string o, e; cin >> o >> e;
	char res[o.size() + e.size()];
	for (int i = 0; i < o.size(); i++)
	{
		res[2 * i] = o[i];
	}
	for (int i = 0; i < e.size(); i++)
	{
		res[2 * i + 1] = e[i];
	}

	for (int i = 0; i < o.size() + e.size(); i++)
	{
		cout << res[i];
	}
	cout << endl;
	return 0;
}
