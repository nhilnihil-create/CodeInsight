#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    // Your code here!
    ll c5=0,c7=0,a[3];
    rep(0,i,3)cin>>a[i];
    rep(0,i,3){
        if(a[i]==7)++c7;
        if(a[i]==5)++c5;
    }
    if(c7==1&&c5==2)cout<<"YES";
    else cout<<"NO";
}
