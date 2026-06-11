#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;cin>>s;
	int l=s.size()-1;
	if(l%2&&s[0]==s[l])puts("First");
	else if(l%2)puts("Second");
	else if(s[0]!=s[l])puts("First");
	else puts("Second");
	return 0;
}