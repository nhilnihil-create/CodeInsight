//zdj
#include<cstdio>
#include<cstring>
char s[100010],c[120];
signed main()
{
	scanf("%s",s),c[98]=0,c[100]=2,c[112]=1,c[113]=3;int l(strlen(s)),ll(l>>1);
	for(register int i(0);i<=ll;i++)
		if(c[s[i]]^((c[s[l-i-1]]+2)%4))
			return puts("No"),0;
	return puts("Yes"),0;
}