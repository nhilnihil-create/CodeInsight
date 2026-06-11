#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    int ans=1;
    bool u=false,d=false;
    for(int i=0; i<n-1; ++i){
        if(a[i]<a[i+1])u=true;
        if(a[i]>a[i+1])d=true;
        if(u&d)u=false,d=false,ans++;
    }
    cout<<ans<<endl;
    return 0;
}
