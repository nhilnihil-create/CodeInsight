#include<deque>
#include<stdint.h>
#include<set>
#include<stack>
#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
using namespace std;
int n,m,d,i,j,col[2010];
char ss[4]={'R','Y','B','G'};
int main()
{
	cin>>n>>m>>d;
	for (i=d;i<=2000;i++)
	{
		col[i]=1-col[i-d];
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			cout<<ss[col[i+j]*2+col[i-j+1000]];
		}
		cout<<endl;
	}
	return 0;
}