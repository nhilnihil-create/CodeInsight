#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
  cin>>n;
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
 
    ll result=0;
    for(ll i=n-1;i>=0;i--){
        result+=(((a[i]+result+b[i]-1)/b[i])*b[i]-(a[i]+result));
    }
 
    cout<<result;
    return 0;
}