#include<bits/stdc++.h>
using namespace std;
inline int getint(void);
int main(void)
{
	int a=getint(),b=getint(),c=getint();
	if(b-a==c-b) printf("YES");
	else printf("NO");
	return 0;
}
inline int getint(void)
{
    int n=0,f=1;
	char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n*f;
}