#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	vector<int> Pillar(3);
	for (int i = 0; i < 3; i++)
		cin >> Pillar.at(i);

	int		tmp = Pillar.at(1) - Pillar.at(0);

	cout << (Pillar.at(2) == Pillar.at(1) + tmp ? "YES" : "NO") << endl;
}