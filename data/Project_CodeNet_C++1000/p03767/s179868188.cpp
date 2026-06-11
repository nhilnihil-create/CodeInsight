#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    long long int n,sum=0;
    cin>>n;
    long long int a[3*n+5];
    for(long long int i=0;i<3*n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+3*n,greater<int>());
    for(long long int i=1;i<=2*n;i+=2) sum=sum+a[i];
    cout<<sum;
    return 0;
}
