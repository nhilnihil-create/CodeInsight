#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll arr[100000];
ll tree[100000],n;

void update(ll idx,ll val,ll n)
{
    while(idx<=n){
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}

int read(ll idx)
{
    ll sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

int main()
{
    ll n,m,x=1;
    cin>>n>>m;
    if(abs(n-m)>=2)cout<<0;
    else{
        for(int i=n;i>=1;i--){
            x*=i;
            x%=(1000000007);
        }
        for(int i=m;i>=1;i--){
            x*=i;
            x%=(1000000007);
        }
        if(n!=m)cout<<x;
        else {
            x*=2;
            x%=(1000000007);
            cout<<x;
        }
    }

    return 0;
}
