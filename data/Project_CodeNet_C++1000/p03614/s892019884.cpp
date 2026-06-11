#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<set>
#include<cstring>
#include<algorithm>
#include<cmath>
#define max_n
using namespace std;
typedef long long ll;
int a[100000+20];

int main ()
{
	int n,i,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==i+1)
			ans++;
	}
	for(i=0;i<n-1;i++)
	{
		if(a[i]==i+1&&i+2==a[i+1])
		{
			ans--;
			i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}