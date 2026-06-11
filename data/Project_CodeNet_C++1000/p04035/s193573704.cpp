#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define p pair<int,int>
#define pb push_back
#define endl '\n'
#define w(t) ll test;cin>>test;while(test--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define pi acos(-1)

int main()
{
    fast;
    ll n;
    cin>>n;
    ll l;
    cin>>l;
    vector<ll> vec(n);
    for(auto &i:vec)
    {
        cin>>i;
    }
    int temp=0;
    for(int i=0;i<n-1;i++)
    {
        if(vec[i]+vec[i+1]>=l)temp=i+1;
    }
    if(!temp)cout<<"Impossible"<<endl;
    else
    {
        cout<<"Possible"<<endl;
        for(int i=1;i<temp;i++)
        {
            cout<<i<<endl;
        }
        for(int i=n-1;i>temp;i--)
        {
            cout<<i<<endl;
        }
        cout<<temp;
    }
}

