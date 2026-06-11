#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	int same = 0;
	for (int i = 0; i < n; i++)
	{
		if(s.substr(i) == t.substr(0, n - i)) {
			same = n - i;
			break;
		}
	}
	cout << 2 * n - same << endl;
	return 0;
}
