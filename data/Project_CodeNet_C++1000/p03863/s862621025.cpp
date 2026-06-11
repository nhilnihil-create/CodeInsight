#include<bits/stdc++.h>
using namespace std;
int l;
string s;
int main() {
	cin >> s;
	l = s.size();
	if(l & 1 && s[0] != s[l - 1] || !(l & 1) && s[0] == s[l - 1])
		cout << "First\n";
	else
		cout <<"Second\n" ;
	return 0;
}