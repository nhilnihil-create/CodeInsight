#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,b,n) for(int i=b;i<(int)n;i++)
#define rep(i,n) REP(i,0,n)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    ll tot=0,x=0,ans=1e9*n+1;
    rep(i,n)tot+=a[i];
    rep(i,n){
        x+=a[i];
        if(i+1<n)ans=min(ans,abs(tot-2*x));
    }
    cout<<ans<<endl;
    return 0;
}
