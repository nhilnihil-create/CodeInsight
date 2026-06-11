#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,x,y;
    cin>>n>>m;
    int a[n]= {};
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&x,&y);
        ++a[x-1];
        ++a[y-1];
    }
    for(int i=0; i<n; i++)
        printf("%d\n",a[i]);
}


