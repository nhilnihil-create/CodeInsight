#include <bits/stdc++.h>
using namespace std;

int main() {
	string w;
	cin >> w;

	vector<int> al(26);

	for (int i = 0; i < w.size(); ++i)
	{
		al.at(w.at(i)-97) += 1;
	}

	for (int i = 0; i < al.size(); ++i)
	{
		if (al.at(i)%2==1)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
