#include <bits/stdc++.h>
#include <cstring>
using namespace std;
 
#define ll long long
#define mod 1000000007
 
void ans(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    ll ans=0;
    for(int i=0;i<n-1;i++){
        ll x=arr[i+1]-arr[i];
        ans+=min(a*x,b);
    }
    cout<<ans;
}
 
int main() {
    ans();
}