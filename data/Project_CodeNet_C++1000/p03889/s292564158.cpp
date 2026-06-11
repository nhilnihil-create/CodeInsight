#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
template<class T>inline void read(T&X)
{
	X = 0;
	char symbol('\0'),ch(getchar());
	for(;ch<'0'||'9'<ch;(!(ch^'-'))?(symbol='\1'):(1),ch=getchar());
	for(;'0'<=ch&&ch<='9';X=(X<<3)+(X<<1)+(ch^48),ch=getchar());
	(symbol)?(X=-X):(1);
}
char s[100007];
int get[128];
const int MODIT=4;
int main()
{
	get['b'] = 0;
	get['p'] = 1;
	get['d'] = 2;
	get['q'] = 3;
//	gets(s+1);
	scanf("%s",s+1);
	int l=strlen(s+1),i;
//fprintf(stderr,"l = %d\n",l);
	for(i=1;i<=(l>>1)+1;++i)
	{
		if(get[s[i]]^((get[s[l-i+1]]+2)%4)) return printf("No\n"),0;
	}
//	for(i=1;i<=l;++i)
//	{
//		fprintf(stderr,"%c = %d   %c = %d\n",s[i],get[s[i]],s[l-i+1],get[s[l-i+1]]);
//	}
//	getchar();
//	getchar();
	return printf("Yes\n"),0;
}

