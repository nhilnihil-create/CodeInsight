#include "bits/stdc++.h"
using namespace std;

int main() {
	int n,m=1;
	int push = -1;
	cin >> n;

	vector<int> btn(n+1, 0);
	for (int i = 0; i < n; i++) cin >> btn.at(i+1);
	for (int i = 0; i < n; i++)
	{
		m = btn.at(m);
		if (m == 2)
		{
			push = i + 1;
			break;
		}
	}
		cout << push << endl;

}