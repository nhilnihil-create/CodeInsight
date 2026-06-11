#include<bits/stdc++.h>
using namespace std;
// abc048 D
int main()
{
	string s;
	cin >> s;
	int n = (int)s.length();
	bool first;
	if(s[0] == s[n-1]) {
		if(n % 2 == 0) first = true;
		else first = false;
	} else {
		if(n % 2 == 0) first = false;
		else first = true;
	}
	
	if(first) {
		puts("First");
	} else {
		puts("Second");
	}
}
