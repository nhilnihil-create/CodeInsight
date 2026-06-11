#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int32_t main()
{
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        cout<<sum+y-a[x]<<endl;
    }
}