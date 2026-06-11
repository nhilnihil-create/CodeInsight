#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,j,k,l,m,a,c1,c2,s;
    s=0;
    cin>>n;
    long long arr[n+10];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    c1=0;
    c2=s;
    l=1000000000000000;
    for(i=0;i<n-1;i++)
    {
        c1+=arr[i];
        s-=arr[i];
        k=abs(c1-s);
        if(k<l)
        {
            l=k;
        }

    }
    cout<<l<<endl;
    return 0;
}
