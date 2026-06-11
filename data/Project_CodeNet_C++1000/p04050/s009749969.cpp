#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
inline int read()
{
	char x = getchar();
	int lin = 0, f = 1;
	while(x < '0' || x > '9')
	{
		if(x == '-') f = -1;
		x = getchar();
	}
    while(x >= '0' && x <= '9')
	{
		lin = lin * 10 + x - '0';
		x = getchar();
	}
	return lin * f;
}
#define PII pair<int,int>
#define fir first
#define sec second
#define ma(a,b) make_pair(a,b)
int a[maxn],n,m,id,b[maxn];
int main(){
	n = read(); m = read();
	for(int i = 1; i <= m; i++)
	{
		a[i] = read();
		if(a[i] & 1) ++id;
	}
	if(m == 1)
	{
		printf("%d\n",a[1]);
		if(a[1] == 1) printf("1\n1");
		else printf("2 \n%d %d",a[1] - 1,1);
		return 0;
	}
	if(id > 2)
	{
		printf("Impossible");
		return 0;
	}
	for(int i = 1; i <= m; i++)
		if(a[i] & 1)
		{
			swap(a[i],a[1]);
			break;
		}
	for(int i = m; i > 1; i--)
		if(a[i] & 1)
		{
			swap(a[i],a[m]);
			break;
		}
	for(int i = 1; i <= m; i++)
		printf("%d ",a[i]);
	puts("");
	for(int i = 1; i <= m; i++)
		b[i] = a[i];
	++b[1],--b[m];
	if(!b[m]) --m;
	printf("%d\n",m);
	for(int i = 1; i <= m; i++)
		printf("%d ",b[i]);
}