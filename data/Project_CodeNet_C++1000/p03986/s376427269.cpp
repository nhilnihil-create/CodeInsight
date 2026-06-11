#include<cstdio>
#include<cstring>
const int N=200005;
int n,s[N],t,a;char c[N];
int main()
{
	scanf("%s",c+1),a=n=strlen(c+1);
	for(int i=1;i<=n;++i)
		if(t&&s[t]=='S'&&c[i]=='T')--t,a-=2;
		else s[++t]=c[i];
	return printf("%d",a),0;
}