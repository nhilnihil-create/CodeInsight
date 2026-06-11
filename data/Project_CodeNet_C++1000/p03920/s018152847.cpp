#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int N,sum,cnt;
	while(~scanf("%d",&N))
	{
		sum = 0;
		cnt = 0;
		for(int i=1;i<=N;i++)
		{
			sum += i;
			cnt = i;
			if(sum >= N)
			break;
		}
		if(sum == N)
		{
			for(int i=1;i<=cnt;i++)
			printf("%d\n",i);
		}
		else 
		{
			int tmp = sum-N;
			for(int i=1;i<=cnt;i++)
			{
				if(tmp != i)
				printf("%d\n",i);
			}
		}
		
	}
	return 0;
}