#include <bits/stdc++.h>
using namespace std;
const int N=505;
int n;
int ans[N*N];
struct number{int x,id;}num[N];

inline bool cmp(number a,number b){return a.x<b.x;}

int main(){
	scanf("%d",&n);
	for (register int i=1; i<=n; ++i) scanf("%d",&num[i].x),num[i].id=i;
	sort(num+1,num+n+1,cmp);
	
	int now=1;
	for (register int i=1; i<=n; ++i)
	{
		ans[num[i].x]=num[i].id;
		for (register int j=1; j<num[i].id; ++j)
		{
			while (ans[now]) 
			{
				if (now==num[i].x)
				{
					puts("No");
					return 0;	
				}
				now++;
			}
			ans[now]=num[i].id;
		}
	}
	now=n*n;
	for (register int i=n; i>=1; --i)
	{
		for (register int j=n; j>num[i].id; --j)
		{
			while (ans[now])
			{
				if (now==num[i].x)
				{
					puts("No");
					return 0;
				}
				now--;	
			}
			ans[now]=num[i].id;
		}
	}
	
	puts("Yes");
	for (register int i=1; i<=n*n; ++i) printf("%d ",ans[i]); 
return 0;
}