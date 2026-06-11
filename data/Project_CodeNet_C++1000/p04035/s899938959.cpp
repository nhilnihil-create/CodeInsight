#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int a[N];
int main()
{
	int n,l,f=0;scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(f)continue;
        if(i>1&&a[i]+a[i-1]>=l)f=i-1;
    }
    if(!f){printf("Impossible\n");return 0;}
    printf("Possible\n");
    for(int i=1;i<=f-1;i++)printf("%d\n",i);
    for(int i=n-1;i>f;i--)printf("%d\n",i);
    printf("%d\n",f);
}
