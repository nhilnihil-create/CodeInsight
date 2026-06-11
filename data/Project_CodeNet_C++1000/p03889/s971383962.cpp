// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
char s[100009];
int main()
{
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<=l/2;i++)
	{
		if(s[i]=='p' && s[l-i-1]!='q')
		{
			printf("No");
			return 0; 
		}
		if(s[i]=='q' && s[l-i-1]!='p')
		{
			printf("No");
			return 0; 
		}
		if(s[i]=='b' && s[l-i-1]!='d')
		{
			printf("No");
			return 0; 
		}
		if(s[i]=='d' && s[l-i-1]!='b')
		{
			printf("No");
			return 0; 
		}
	}
	printf("Yes");
}	