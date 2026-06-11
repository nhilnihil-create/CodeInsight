#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n,mx=0,ans=0;cin>>n;
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        if(a>mx){
            mx=a;
            ans=a+b;
        }
    }
    cout<<ans;
}



