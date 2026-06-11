#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int len;
char c[100001];
map<char,char>m;
int main()
{
	m['b']='d',m['d']='b',m['p']='q',m['q']='p';
	scanf("%s",&c);
	len=strlen(c);
	if(len&1)
	{
	    puts("No");
	    return 0;
	}
	for(int i=0;i<len>>1;++i)
	{
		if(c[i]!=m[c[len-i-1]])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}