#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
    long long int i,j,k,n,x,z=0,y=0,mn=10000000000,sum=0;
    vector<long long int>v;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
        sum+=x;
    }
    for(i=0;i<n-1;i++)
    {
        y+=v[i];
        z=sum-y;
        mn=min(mn,abs(z-y));
    }
    cout<<mn<<endl;

}
