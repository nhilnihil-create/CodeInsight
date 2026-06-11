#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    map<ll,ll>mp;
    rep(i,n){
        mp[a[i]]++;
    }
    ll cnt=0;
    for(auto p:mp){
        if(p.second%2==1)cnt+=1;
    }
    cout<<cnt<<endl;
}