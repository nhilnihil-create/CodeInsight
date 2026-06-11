#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],b[N];
int n;
bool check(int x)
{
    int L=1,R=2*n-1;
    for(int i=1;i<=2*n-1;i++)
        b[i]=(a[i]>=x);
    for(int i=1;i<n;i++)
        if(b[i]==b[i+1])
            L=i+1;
    for(int i=2*n-1;i>n;i--)
        if(b[i]==b[i-1])
            R=i-1;
    if(n-L<R-n)
        return (b[L]==1);
    else
        return (b[R]==1);
}
int main()
{
    cin>>n;
    for(int i=1;i<=2*n-1;i++)
        cin>>a[i];
    int low=1,high=2*n-1,ans=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(check(mid))
        {
            low=mid+1;
            ans=mid;
        }
        else
            high=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
