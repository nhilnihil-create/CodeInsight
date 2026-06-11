#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	string s,t;
	int i,x;
	cin >> s;
	t = s;
	x = s.size();
	for (i = 0; i < x; i++) {
		if (s[i] == 'b') t[x - i - 1] = 'd';
		else if (s[i] == 'd') t[x - i - 1] = 'b';
		else if (s[i] == 'p') t[x - i - 1] = 'q';
		else if (s[i] == 'q') t[x - i - 1] = 'p';
	}
	printf((s == t) ? "Yes\n" : "No\n");
	return 0;
}