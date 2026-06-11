#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    ll tt;
    cin>>tt;
    vector<ll>t(n);
    rep(i,n)cin>>t[i];
    ll saidai=t[n-1]+tt;
    vector<ll>sa(n-1);
    ll hiku=0;
    for(int i=1;i<n;i++){
        sa[i-1]=t[i]-t[i-1];
        if(sa[i-1]<=tt)sa[i-1]=0;
        else sa[i-1]-=tt;
        hiku+=sa[i-1];
    }
    saidai-=hiku;
    cout<<saidai<<endl;
}