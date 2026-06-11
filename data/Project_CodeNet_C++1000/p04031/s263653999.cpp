#include<bits/stdc++.h>
using namespace std;
int ara[500];
int main()
{
    int n,mn,sum,p;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ara[i];
    sort(ara,ara+n);
    mn=1e12;
    for(int i=ara[0];i<=ara[n-1];i++)
    {
        sum=0;
        for(int j=0;j<n;j++)
        {
            p=(ara[j]-i);
            sum+=(p*p);
        }
        if(sum<mn)
            mn=sum;
    }
    cout<<mn<<endl;

    return 0;
}
