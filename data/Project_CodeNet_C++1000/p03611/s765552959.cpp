#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(ll i=0;i<(n);i++)

int main(){
    ll n;
    cin>>n;
    vector<int>a(100020,0);
    
    rep(i,n){
        ll c;
        cin>>c;
        a[c]++;
    }
    int mx=0;
    rep(i,100020){
       int tmp=a[i]+a[i-1]+a[i+1];
       mx=max(mx,tmp);
    }
    cout<<mx<<endl;
}