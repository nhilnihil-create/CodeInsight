#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    vector<ll>b(0);
    for(int i=n-1;i>=0;i-=2){
        b.push_back(a[i]);
    }
    if(a.size()%2==0){
        for(int i=0;i<n;i+=2){
            b.push_back(a[i]);
        }
    }
    else{
        for(int i=1;i<n;i+=2){
            b.push_back(a[i]);
        }
    }
    rep(i,n){
        if(i<n-1)cout<<b[i]<<" ";
        else cout<<b[n-1]<<endl;
    }
}