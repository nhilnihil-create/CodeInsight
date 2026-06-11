#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[250000],n;
bool comp(ll a,ll b)
{
    return a>b;
}

ll segment(ll i)
{
    if(i==n)
        return i-1;
    if(arr[i]!=arr[i+1])
        return i;
    return segment(i+1);
}
int main()
{
    ll tc,m,i,a=1,b,flag=0,cnt=0;
    cin>>n;

    for(i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n,comp);
    for(i=0;i<n;i++)
    {
        ll tt=segment(i);

        if(tt-i+1>=4&&flag==0)
        {
            cout<<arr[i]*arr[i]<<endl;exit(0);
        }
       if(tt-i+1>=2)
       {
           a*=arr[i];flag=1;
        cnt++;
        if(cnt==2) {cout<<a<<endl;exit(0);}

       }
            i=tt;

    }
  cout<<0<<endl;





}
