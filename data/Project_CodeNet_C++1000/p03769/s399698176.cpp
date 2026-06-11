#include<cstdio>
#include<queue>
using namespace std;
char st[50];
deque<int >q1;
deque<int >q2;
int main()
{
	//freopen("fkstring.in","r",stdin);
	//freopen("fkstring.out","w",stdout);
	long long n;
	scanf("%lld",&n);
	int cnt=0;
	n++;
	while(n)
	{
		st[++cnt]=n&1;
		n>>=1;
	}
	int tmp=0;
	for(int i=cnt-1;i>=1;i--)
	{
		tmp++;
		q1.push_back(tmp);
		q2.push_back(tmp);
		if(st[i]==1)
		{
			tmp++;
			q1.push_back(tmp);
			q2.push_front(tmp);
		}
	}
	int end=q1.size()+q2.size();
	printf("%d\n",end);
	while(q1.size())
	{
		printf("%d ",q1.front());
		q1.pop_front();
	}
	while(q2.size())
	{
		printf("%d ",q2.front());
		q2.pop_front();
	}
	return 0;
}