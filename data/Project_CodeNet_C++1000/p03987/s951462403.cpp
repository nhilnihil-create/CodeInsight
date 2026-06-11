#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=4e5+500;
int n,w[N],q[N];
int main()
{
    scanf("%d",&n);int top=0;long long ans=0,s=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        while(top&&w[i]<w[q[top]])s-=1ll*(q[top]-q[top-1])*w[q[top]],--top;
        q[++top]=i,s+=1ll*w[i]*(q[top]-q[top-1]);
        ans+=s;
    }
    cout<<ans<<endl;
}