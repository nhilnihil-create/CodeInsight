#include<bits/stdc++.h>
using namespace std;
 typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll a[100000] = {};
    ll b[100000] = {};
    ll count=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(ll i=1;i<n;i++)
    {
        if(a[i] == a[i-1])
        {
            b[i] = a[i];count++;
        }
    }
    if(count%2 == 1)count++;
    cout<<n-count;


}