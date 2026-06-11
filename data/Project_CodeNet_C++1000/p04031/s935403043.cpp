#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,sum=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
    }
    if((sum*1.0/n)>(sum/n+.50))
        sum=sum/n+1;
    else
        sum=sum/n;
    long long total=0;
    for(i=0;i<n;i++)
        total=total+(a[i]-sum)*(a[i]-sum);
    cout<<total<<endl;

}
