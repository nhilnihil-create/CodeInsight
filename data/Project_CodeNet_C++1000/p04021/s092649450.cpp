#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100000],b[100000],cnt=1,ans;
map<ll,ll> mp;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++){
        mp[b[i]]=cnt++;
    }
    for(int i=0;i<n;i++){
        a[i]=mp[a[i]];
    }
    for(int i=0;i<n;i+=2){
        if(a[i]%2==0)ans++;
    }
    cout<<ans<<endl;
}
