#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<map> 
using namespace std;
int a[100005];
map<int,int>mp;
string st="CODEFESTIVAL2016";
int main()
{
	char s[20];
	scanf("%s",s);
	int ans=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]!=st[i])ans++;
	}
	printf("%d\n",ans);
	return 0;
}