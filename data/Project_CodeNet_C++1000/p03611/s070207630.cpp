#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n,m;
    scanf("%d",&n);
    int x[3*100005];
    memset(x,0,sizeof(x));
    int max1=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        x[m+1]++;
        x[m-1]++;
        x[m]++;
    }
    for(int i=0;i<3*100005;i++)
        max1=max(max1,x[i]);
    printf("%d\n",max1);
    return 0;
}