#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
#define MAXN 200
using namespace std;
typedef long long LL;
LL N;
int len,digit[MAXN+5];
deque<int> que;
void Work(LL x)
{
	len=0;
	while(x)
	{
		digit[++len]=x%2;
		x/=2;
	}
}
int main()
{
	scanf("%lld",&N);
	N++;
	Work(N);
	int id=0;
	for(int i=len-1;i>=1;i--)
	{
		que.push_back(++id);
		if(digit[i]==1)
			que.push_front(++id);
	}
	printf("%d\n",id*2);
	for(int i=0;i<(int)que.size();i++)
		printf("%d ",que[i]);
	for(int i=1;i<=id;i++)
		if(i==1)
			printf("%d",i);
		else
			printf(" %d",i);
	printf("\n");
	return 0;
}