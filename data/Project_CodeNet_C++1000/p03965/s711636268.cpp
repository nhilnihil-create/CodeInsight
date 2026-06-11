#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	
	map<char, int> counter;
	for (int i = 0; i < s.size(); i++) counter[s[i]]++;

	int ans = s.size() / 2 - counter['p'];
	printf("%d\n", ans); 
	return 0;
}