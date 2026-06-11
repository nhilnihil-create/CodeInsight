#include<bits/stdc++.h>
using namespace std;
char s[100009],s2[100009];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for (int i=0;i<len;i++)
	{
		if (s[i]=='b') s2[len-i-1]='d';
		else if (s[i]=='d') s2[len-i-1]='b';
		else if (s[i]=='q') s2[len-i-1]='p';
		else s2[len-i-1]='q';
	}
	if (strcmp(s,s2)==0) printf("Yes");
	else printf("No");
	return 0;
}