#include<bits/stdc++.h>
using namespace std;
int h,w,d;
char c[4]={'R','Y','G','B'};
int main()
{
	scanf("%d%d%d",&h,&w,&d);
	for(int i=1;i<=h;i++,puts(""))
		for(int j=1;j<=w;j++)
		{
			int x=i+j+w,y=i-j+w;
			putchar(c[((x/d*2)&2)|((y/d)&1)]);
		}
	return 0;
}
