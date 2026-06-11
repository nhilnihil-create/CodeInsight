#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    ll n; cin>>n;
    unsigned long long odd=0,even=0,sum=0;
    rep(i,n){
        ll a;
        cin>>a;
        if(a%2==0){
            odd++;//偶数
        }else{
            even++;//奇数
        }
        sum+=a;
    }
    /*
    bool ok;
    if(odd%2!=0 && even%2==0){
        ok=true;
    }else if(odd%2==0 && even%2!=0){
        ok=false;
    }
    if(ok) cout<<"YES\n"; 
    else cout<<"NO\n"; 
    */
    if(sum%2==0) cout<<"YES\n";
    else if(sum%2!=0) cout<<"NO\n";
}