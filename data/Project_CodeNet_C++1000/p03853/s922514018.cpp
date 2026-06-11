#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define debug(x) cout<<x<<"\n";
#define sc scanf
#define Max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
const int N=1e5+10;
const ll inf=0x3f3f3f3f3f3f;
using namespace std;
char arr[110][110];
int main()
{	
	int n,m;
	while(sc("%d%d",&n,&m)==2)
	{
		for(int i=0;i<n;i++)
		sc("%s",arr[i]);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<2;j++)
			printf("%s\n",arr[i]);
		}
	}
	return 0;
} 