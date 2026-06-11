#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
const long long int m=pow(10,9)+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,max=-1,sum=0;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int f[100005]={0};
    for(int i=0;i<n;i++)
    {
        f[a[i]]++;
    }
    for(int i=0;i<100005-2;i++)
    {
        sum=f[i]+f[i+1]+f[i+2];
        if(sum>max)
            max=sum;
    }
    cout<<max<<endl;
    return 0;
}