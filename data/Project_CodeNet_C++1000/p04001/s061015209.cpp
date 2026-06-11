#include<bits/stdc++.h>
using namespace std;
char input[20];
long long totalsum = 0;
int len,cross[20],num[20];

void fuck(int lvl)
{
	if(lvl == len)
	{
		long long sum = num[0];
		int i;
		for(i=1;i<=len;i++)
		{
			if(cross[i] == 0)
			{
				sum *= 10;
				sum += num[i];
			}
			else if(cross[i] == 1)
			{
				totalsum += sum;
				sum = 0;
				if(i!=len)
				{
					sum += num[i];
				}
			}
		}
		return;
	}
	
	cross[lvl] = 1;
	fuck(lvl+1);
	
	cross[lvl] = 0;
	fuck(lvl+1);
	
	return;
}

int main()
{
	int i,j,k;
	
	scanf("%s",input);
	len = strlen(input);
	cross[len] = 1;
	for(i=0;i<len;i++)
	{
		num[i] = input[i] - '0';
	}
	fuck(1);
	
	

	printf("%lld\n",totalsum);
	
}