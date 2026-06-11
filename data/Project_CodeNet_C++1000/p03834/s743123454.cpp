#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < 19; i++){
		if (s[i] != ',')
			cout << s[i];
		else
			cout << " ";

	}
	return 0;
	}



