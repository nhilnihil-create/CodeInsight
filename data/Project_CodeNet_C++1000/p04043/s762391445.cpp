#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	map<int, int> temp;
	temp[a]++;
	temp[b]++;
	temp[c]++;

	if (temp[5] == 2 && temp[7] == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}