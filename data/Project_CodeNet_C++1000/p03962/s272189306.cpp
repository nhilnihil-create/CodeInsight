#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, count;
	bool flag[100] = {};

	cin >> a >> b >> c;

	flag[a - 1] = true;
	flag[b - 1] = true;
	flag[c - 1] = true;

	for (int i = 0; i < 100; i++) {
		if (flag[i]) {
			count++;
		}
	}

	cout << count << endl;
}
