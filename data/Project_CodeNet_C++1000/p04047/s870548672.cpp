#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin>>n;
    ll ar[n*2];
    for(int i=0;i<2*n;i++)
    {
        cin>>ar[i];
    }
    ll sum=0;
    sort(ar,ar+(2*n));
    for(int i=0;i<2*n;i+=2)
    {
        sum+=ar[i];
    }
    cout<<sum;
}