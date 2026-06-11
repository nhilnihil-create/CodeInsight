#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int ara[N];
int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        ara[x]++;
    }
    int p=1;
    if(ara[0]!=1 && ara[0]!=0)
        p=0;

    for(int i=1;i<N;i++)
        if(ara[i]!=2 &&  ara[i]!=0)
            p=0;
    if(p==0)
        cout<<p<<endl;
    else
    {
        long long int ans=1,t=1000000007;
        for(int i=1;i<=(n/2);i++)
        {
            ans=(ans*2)%t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
