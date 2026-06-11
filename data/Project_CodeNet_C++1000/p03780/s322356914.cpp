#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,ans,sum=0,a[5010];
    cin>>n>>k;
    ans=n;
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(i=n-1; i>=0; i--)
    {
        if(sum+a[i]<k) sum+=a[i];
        else ans=i;
    }
    cout<<ans<<endl;
    return 0;
}
