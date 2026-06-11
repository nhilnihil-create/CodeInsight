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
    if(s%10!=0)
        {cout<<s<<endl;return 0;}
    else
    {
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if((s-a[i])%10!=0)
                {cout<<s-a[i]<<endl;return 0;}
        }
        cout<<"0"<<endl;
    }
}