#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,n,c=0;
    cin>>n;
    int a[n+1]={};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[a[i]]==i)c++;
    }
    cout<<c/2<<endl;
    return 0;
}