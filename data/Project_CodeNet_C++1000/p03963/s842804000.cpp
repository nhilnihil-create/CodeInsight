#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans=1,n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        if(i==0)
            ans*=k;
        else
            ans*=(k-1);
    }
    cout<<ans;
    return 0;
}

