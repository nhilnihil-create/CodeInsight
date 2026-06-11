#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	char s[1000001];
	scanf("%s",&s);
	int len=strlen(s);
	int flag=1;
	if(len%2==1)
	{
		printf("No\n");
		return 0;
	}
	for(int i=0;i<=len/2+1;i++)
	{
		if(s[i]=='d')
		{
			if(s[len-1-i]!='b')
			{
				flag=0;
				break;
			}
		}
		if(s[i]=='b')
		{
			if(s[len-1-i]!='d')
			{
				flag=0;
				break;
			}
		}
		if(s[i]=='p')
		{
			if(s[len-1-i]!='q')
			{
				flag=0;
				break;
			}
		}
		if(s[i]=='q')
		{
			if(s[len-1-i]!='p')
			{
				flag=0;
				break;
			}
		}
	}
    if(flag==0)printf("No\n");
    else printf("Yes\n");
    return 0;
}