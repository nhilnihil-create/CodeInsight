#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[10086],n,k,ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>n-k-1;i--)
    {
        ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}