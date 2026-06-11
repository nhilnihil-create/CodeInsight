#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int k = 0;
	string c = "CODEFESTIVAL2016";
	for(int i = 0;i < 16;i++)
	{
		if(s.at(i) != c.at(i))
		{
			k++;
		}
	}
	cout << k << endl;
	return 0;
}
