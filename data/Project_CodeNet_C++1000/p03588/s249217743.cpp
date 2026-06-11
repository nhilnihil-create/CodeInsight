#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;
using ll = long long;

int main(){
    ll n,imin=0,ans;
    cin>>n;
    rep(i,n){
        ll a,b;
        cin>>a>>b;
        if(a>imin){
            ans=a+b;
            imin=a;
        }
    }
    cout<<ans;
}