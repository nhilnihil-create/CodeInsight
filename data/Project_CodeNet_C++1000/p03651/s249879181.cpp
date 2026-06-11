#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    int p=a[0];
    for(int i=0;i<n;i++)
    {
        p=__gcd(p,a[i]);
    }
    if(k>maxi)
    cout<<"IMPOSSIBLE"<<endl;
    else if(k%p==0)
    {
        cout<<"POSSIBLE"<<endl;
    }
    else
    cout<<"IMPOSSIBLE"<<endl;
    
}