#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
char s[100005];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if(s[1]==s[n])
	{
		if(n%2==0)
			puts("First");
		else
			puts("Second");
	}
	else
	{
		if(n%2==0)
			puts("Second");
		else
			puts("First");
	}
	return 0;
}
