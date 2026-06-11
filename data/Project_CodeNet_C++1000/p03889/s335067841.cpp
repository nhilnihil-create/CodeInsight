#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
	string s;
	cin>>s;
	string x=s;
	reverse(s.begin(),s.end());
	int n=s.length();
	for(int i=0;i<n;++i)
	{
		if(s[i]=='b')s[i]='d';
        else if(s[i]=='d')s[i]='b';
        else if(s[i]=='p')s[i]='q';
        else if(s[i]=='q')s[i]='p';
	}
	if(x==s)puts("Yes");
	else puts("No");
	return 0;
}