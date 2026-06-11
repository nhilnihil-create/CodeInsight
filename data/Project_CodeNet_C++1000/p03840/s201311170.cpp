#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int a1,a2,a3,a4,a5,a6,a7;
    scanf("%d%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6,&a7);
    int t=min(a4,a5);
    long long ans=a2;
    ans+=max(2ll*(a1/2+a4/2+a5/2),(a1&&a4&&a5?(2ll*((a1-1)/2+(a4-1)/2+(a5-1)/2)+3):0ll));
    cout<<ans<<endl;
}