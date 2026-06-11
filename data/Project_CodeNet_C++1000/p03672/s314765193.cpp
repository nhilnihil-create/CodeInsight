#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int kazu[128] = {};
	string now;
	for (int i = 1; i < s.size(); i += 2)
	{
		now = s;
		now.erase(s.size()-1-i);
		if(now.substr(0,now.size()/2) == now.substr(now.size()/2,now.size()/2))
		{
			cout << now.size() << endl;
			break;
		}
	}
	return 0;
}