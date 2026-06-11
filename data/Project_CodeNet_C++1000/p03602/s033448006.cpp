#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 305

using namespace std;
typedef long long int ll;

ll A[SIZE][SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) scanf("%lld",&A[i][j]);
	}
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			bool up=false;
			for(int k=0;k<n;k++)
			{
				if(k==i||k==j) continue;
				if(A[i][j]>A[i][k]+A[k][j])
				{
					puts("-1");
					return 0;
				}
				if(A[i][j]==A[i][k]+A[k][j]) up=true;
			}
			if(!up) ret+=A[i][j];
		}
	}
	printf("%lld\n",ret);
	return 0;
}
