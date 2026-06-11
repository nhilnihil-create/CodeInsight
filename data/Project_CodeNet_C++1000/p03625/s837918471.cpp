#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    map<ll,ll>mpx;
    map<ll,ll>mpy;
    vector<int>a(n);
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        mpx[a[i]]++;
    }
    ll mx=0;
    ll my=0;
    for(auto p:mpx){
        if(p.second>=2){
            mx=max(mx,p.first);
        }
    }
    sort(a.begin(),a.end());
    int cnt=0;
    rep(i,n){
        if(a[i]==mx){
            a[i]=0;
            cnt+=1;
            if(cnt==2)break;
        }
    }
    rep(i,n){
        mpy[a[i]]++;
    }
    for(auto p:mpy){
        if(p.second>=2){
            my=max(my,p.first);
        }
    }
    
    cout<<mx*my<<endl;
}

    
