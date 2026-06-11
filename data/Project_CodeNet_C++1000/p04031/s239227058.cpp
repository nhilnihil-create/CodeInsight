#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    ll n;
    cin >>n;
    vector<ll> arr;
    ll sum=0;
    for(ll i =0;i<n;i++)
    {
        ll temp;
            cin >> temp;
        sum+=temp;
        arr.push_back(temp);
    }
    float mean=float(sum)/n;
    //cout << mean;
    if(mean >=0)
    {

    mean+=0.5;
    }
    else
    {
        mean-=0.5;
    }
    ll intmean=int(mean);
    //cout << intmean;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ll tmp=abs(arr[i]-intmean);
        tmp*=tmp;
        ans+=tmp;
        
    }
    cout << ans;

    

}
