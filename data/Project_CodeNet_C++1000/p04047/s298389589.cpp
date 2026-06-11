#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
int a[10005],ans=0,n;
int main()
{
    cin>>n;
    for(int i=1;i<=2*n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+2*n);   
    for(int i=1;i<=2*n;i+=2)
    {
        ans+=a[i];
    } 
    cout<<ans;
    return 0;
}