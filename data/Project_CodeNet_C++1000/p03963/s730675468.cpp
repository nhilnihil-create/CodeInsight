#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (int)(n); i++)
#define int long long
#define ll long long
using namespace std;
signed main(){
    int a,b;
    cin>>a>>b;
    int ans=1;
    rep(i,a-1){
        ans=ans*(b-1);
    }
    cout<<ans*b<<endl;
    return 0;
}