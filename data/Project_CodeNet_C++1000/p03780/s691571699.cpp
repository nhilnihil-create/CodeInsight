#include<iostream>
#include<algorithm>

using namespace std;

const int sz=5e3+10;
int n,k;
int len,a[sz];
main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    len=0;
    int ans=n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>=k)ans--;
        else a[len++]=x;
    }
    sort(a,a+len);
    int tmp=0;
    while(len>=2)
    {
        tmp+=a[len-1];
        if(a[len-2]+tmp<k)
        {
            len--;
            continue;
        }
        if(a[0]+tmp>=k)
        {
            ans=0;
            break;
        }
        int l=0,r=len-2;
        while(l+1<r)
        {
            int mid=(l+r)/2;
            if(tmp+a[mid]>=k)r=mid;
            else l=mid;
        }
        ans=ans-(len-r);
        len=r;
    }
    cout<<ans<<endl;
}