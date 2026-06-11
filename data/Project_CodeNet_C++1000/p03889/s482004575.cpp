#include<cstdio>
#include<cstring>
char c[125],s[100001],t[100001];
main(){
	c['b']='d',c['d']='b',c['p']='q',c['q']='p';
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<l;++i)t[l-i]=c[s[i]];
	for(int i=0;i<l;++i)
		if(s[i]!=t[i+1])
			return puts("No"),0;
	puts("Yes");
}