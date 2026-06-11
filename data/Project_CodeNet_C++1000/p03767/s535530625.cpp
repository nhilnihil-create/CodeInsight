#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
const long long int m=pow(10,9)+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    n*=3;
    ll c=0;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    unsigned long long int s=0;
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++)
    {
        if(c==n/3)break;
        if(i%2==1)
        {s+=a[i];
        c++;}
    }
    cout<<s<<endl;
    return 0;
}