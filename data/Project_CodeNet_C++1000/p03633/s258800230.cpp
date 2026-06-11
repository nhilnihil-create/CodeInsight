#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,ans=1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long int a;
        cin>>a;
        ans=lcm(ans,a);
    }
    cout<<ans;
}