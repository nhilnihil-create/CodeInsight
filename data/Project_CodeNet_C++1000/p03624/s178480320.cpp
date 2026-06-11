#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s; cin >> s;
	for (char i = 'a'; i <= 'z'; ++i)
		if (s.find(i) == -1)
		{
			cout << i << endl;
			return 0;
		}
	cout << "None" << endl;
}

