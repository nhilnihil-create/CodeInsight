#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll i,j,k,l;

ll mypow(ll a,ll b){
    ll num=1;
    while(b!=0){
        num*=a;
        num%=mod;
        b--;
    }
    return num;
}

int main(){
    ll n;cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){cin>>a[i];}

    ll ans=0;
    sort(a.begin(),a.end());
    if(n%2==1){
        if(a[0]!=0){cout<<0<<endl;return 0;}
        for(i=1;i<n-1;i+=2){
            if(a[i+1]!=a[i]){cout<<0<<endl;return 0;}
        }
        for(i=1;i<n-2;i+=2){
            if(a[i+2]!=a[i]+2){cout<<0<<endl;return 0;}
        }

        ans=(a[n-1])/2;
    }else{
        for(i=0;i<n-1;i+=2){
            if(a[i+1]!=a[i]){cout<<0<<endl;return 0;}
        }
        for(i=0;i<n-2;i+=2){
            if(a[i+2]!=a[i]+2){cout<<0<<endl;return 0;}
        }

        ans=(a[n-1]+1)/2;
    }

    cout<<mypow(2,ans)<<endl;
    return 0;
}