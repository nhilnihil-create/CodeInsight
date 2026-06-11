#include<cstdio>
#include<cstring>
using namespace std;
char s[111111];
char s1[111111];
int l;
int main()
{
	gets(s);
	l=strlen(s);
	for(int i=0;i<l;++i)
	{
		switch(s[l-i-1])
		{
			case 'b':s1[i]='d';break;
			case 'd':s1[i]='b';break;
			case 'p':s1[i]='q';break;
			case 'q':s1[i]='p';break;
		}
	}
	if(strcmp(s,s1))printf("No");
	else printf("Yes");
	return 0;
}