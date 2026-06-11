#include<cstdio>
#include<cstring>
using namespace std;
char s1[501000],s2[501000];
int len;
int main()
{
	scanf("%s",s1);
	len=strlen(s1);
	for(int i=0;i<len;i++)
	{
		s2[len-i-1]=s1[i];
		if(s1[i]=='p') s1[i]='q';
		else if(s1[i]=='q') s1[i]='p';
		else if(s1[i]=='b') s1[i]='d';
		else if(s1[i]=='d') s1[i]='b';
	}
	for(int i=0;i<len;i++)
	{
		if(s1[i]!=s2[i])
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}