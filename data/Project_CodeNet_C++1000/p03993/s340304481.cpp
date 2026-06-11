#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n ;
    cin>>n;
    int* a = new int[n+1];
    for(int i=1;i<n+1;i++)
    {
        cin>>a[i];
    }
    int ans =0;
    for(int i=1;i<=n;i++)
    {
        if( a[ a[i] ]== i)
            ans++;
    }
    cout<<ans/2;
}