#include<bits/stdc++.h>
using namespace std;
#define int long long int

int count(int n)
{
    int res=0;
    while(n!=0)
    {
        res++;
        n/=10;
    }
    return res;
}
int32_t main()
{
    int n;
    cin>>n;
    int ans=INT_MAX;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
        
        ans=min(ans,max(count(i),count(n/i)));
        
        }
    }
    if(ans==INT_MAX)
    cout<<count(n)<<endl;
    else
    cout<<ans<<endl;

}