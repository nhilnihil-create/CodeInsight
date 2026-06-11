#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
int arr[maxn];
struct node
{
    long long int id,val;
}lstk[maxn],rstk[maxn];
long long int pre[maxn];
long long int suf[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>arr[i];
    int len=0;
    for(int i=1;i<=n;++i)
    {
        if(len==0)
        {
            lstk[len].id=i;
            lstk[len++].val=arr[i];
            pre[i]=0;
        }
        else
        {
            while(len>0&&lstk[len-1].val>arr[i])
            {
                --len;
            }
            if(len==0)
                pre[i]=0;
            else
                pre[i]=lstk[len-1].id;
            lstk[len].id=i;
            lstk[len++].val=arr[i];
        }
    }
    len=0;
    for(int i=n;i>=0;--i)
    {
        if(len==0)
        {
            rstk[len].id=i;
            rstk[len++].val=arr[i];
            suf[i]=n+1;
        }
        else
        {
            while(len>0&&rstk[len-1].val>arr[i])
                --len;
            //cout<<i<<"****"<<rstk[len-1].id<<endl;
            if(len==0)
                suf[i]=n+1;
            else
                suf[i]=rstk[len-1].id;
                rstk[len].id=i;
                rstk[len++].val=arr[i];
        }
    }
    long long int sum=0;
    int l,r;
    for(int i=1;i<=n;++i)
    {
        //cout<<pre[i]<<" "<<suf[i]<<endl;
        sum+=(i-pre[i])*(suf[i]-i)*arr[i];
    }
    cout<<sum<<endl;
    return 0;
}
