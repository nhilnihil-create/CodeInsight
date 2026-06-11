#include<bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	int res[4] = {};
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'N') res[0] = 1;
		else if(s[i] == 'W') res[1] = 1;
		else if(s[i] == 'S') res[2] = 1;
		else res[3] = 1;
	}

	if((res[0] + res[2]) % 2 == 0 &&  (res[1] + res[3]) % 2 == 0) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
