#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s; cin >> s;
	char B[26]{0};
	for (int i = 0; i < s.size(); ++i)
		B[s[i]-'a']++;
	for (int i = 0; i < 26; ++i)
		if (!B[i])
		{
			cout << char(97+i) << endl;
			return 0;
		}
	cout << "None" << endl;
}

