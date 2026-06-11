#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,s=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    ll m,x,y,p;
    cin>>m;
    while(m--)
    {
        cin>>x>>y;
        p=s-a[--x]+y;
        cout<<p<<endl;
    }
    return 0;
}