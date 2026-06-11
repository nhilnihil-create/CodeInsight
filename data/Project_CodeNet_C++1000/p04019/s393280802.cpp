#include<cstdio>
#include<cstring>
const int N=1005;
int n,b[N];char c[N];
int main()
{
	scanf("%s",c+1),n=strlen(c+1);
	for(int i=1;i<=n;++i)b[c[i]]=1;
	if(b['N']^b['S']||b['W']^b['E'])
		return printf("No"),0;
	return printf("Yes"),0;
}