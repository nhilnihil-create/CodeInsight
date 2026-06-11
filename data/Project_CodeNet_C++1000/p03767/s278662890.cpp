#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n;cin>>n;
    ll arr[3*n];
    for(int i=0;i<3*n;i++) cin>>arr[i];
    sort(arr,arr+3*n,greater<ll>());
    ll x=0,s=0,i=1;
    while(x<n && i<3*n){
        s+=arr[i];
        i+=2;
        x++;
    }
    cout<<s<<"\n";
}