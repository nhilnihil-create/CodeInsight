#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,mx,smi=1e9,num[100005],ans;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>num[i];
	for (i=1;i<=n;i++)
	{
		if (num[i]-smi>mx)
		{
			mx=num[i]-smi;
			ans=0;
		}
		if (num[i]-smi==mx) ans++;
		smi=min(smi,num[i]);
	}
	cout<<ans;
	return 0;
}