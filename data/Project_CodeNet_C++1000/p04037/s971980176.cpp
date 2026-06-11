#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;++i)

using namespace std;

const int maxn=1e5+10;
int a[maxn],n;

int main(void)
{
	scanf("%d",&n);
	For(i,1,n)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	int x=1,y=1;
	while(y+1<=a[x+1])
		x++,y++;
	int qaq=x+1;
	while(a[qaq]==y)
		qaq++;
	if(((qaq-x)&1)&&((a[x]+1-y)&1))
		puts("Second");
	else
		puts("First");
}
