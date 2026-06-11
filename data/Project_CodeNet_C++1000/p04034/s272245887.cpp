#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n,1);
    vector<bool>ok(n,false);
    ok[0]=true;
    rep(i,m){
        int x,y; cin>>x>>y;
        x--; y--;
        a[x]--; a[y]++;
        if(ok[x])ok[y]=true;
        if(a[x]==0)ok[x]=false;
    }
    int ans=0;
    rep(i,n)if(ok[i])ans++;
    cout<<ans<<endl;
}