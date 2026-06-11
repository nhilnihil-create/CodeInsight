#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    int n,p[200000],ans=0,a=0;
    cin>>n;
    rep(i,n) cin>>p[i];
    rep(i,n){
        if(p[i]==i+1) a++;
        else ans+=(a+1)/2,a=0;
    }
    if(a) ans+=(a+1)/2;
    cout<<ans;
}