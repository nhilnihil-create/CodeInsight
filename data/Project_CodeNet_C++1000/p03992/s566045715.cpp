#include<bits/stdc++.h>

using namespace std;

int n;

int main()
{
	string s;
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		if(i == 4) {
			cout << " ";
		}
		cout << s[i];
	}
	cout << endl;
	return 0;
}
