#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <bitset>
#include <set>
const int maxlongint=2147483647;
const int mo=1e9+7;	
const int N=100005;
using namespace std;
int n,a[N];
int main()
{
	//freopen("agc002e.in","r",stdin);
	//freopen("agc002e.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=n,x=0;i>=1;i--)
	{
		x++;
		if(x>=a[i-1])
		{
			if((a[i]-x)&1)
				printf("First\n");
			else
				for(int j=i;j>=0;j--)
					if(x>=a[j-1]+1)
					{
						if((j-i)&1)
							printf("First\n");
						else
							printf("Second\n");
						break;
					}
			return 0;
		}
	}
}