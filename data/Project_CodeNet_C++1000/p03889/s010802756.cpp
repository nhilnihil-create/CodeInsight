#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
char s[100005];
int ma[205];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	ma['p']=1,ma['q']=4,ma['b']=2,ma['d']=3;
	for(int i=0;i<len;i++)
	{
		if(ma[s[i]]+ma[s[len-i-1]]!=5)
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}