#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
ll mod=1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,ans=0;cin>>n;
    vector<int> p(n);
    rep(i,n)cin>>p[i];
    rep(i,n-1){
        if(p[i]==i+1){
            swap(p[i],p[i+1]);
            ans++;
        }
    }
    if(p[n-1]==n)ans++;
    cout<<ans<<endl;
    return 0;
}
