#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5e5;
int n,K,w[N];
int main()
{
    scanf("%d%d",&n,&K);
    for(int i=1;i<=n;i++)scanf("%d",w+i);
    long long presum=0,sufsum=0,sum=0;
    for(int i=K;i<=n;i++)if(w[i]>0)sufsum+=w[i];
    for(int i=1;i<K;i++)sum+=w[i];long long ans=0;
    for(int i=K;i<=n;i++)
    {
        sum+=w[i]-w[i-K];if(w[i]>0)sufsum-=w[i];
        if(w[i-K]>0)presum+=w[i-K];
        ans=max(ans,max(sum,0ll)+sufsum+presum);
    }
    cout<<ans<<endl;
}