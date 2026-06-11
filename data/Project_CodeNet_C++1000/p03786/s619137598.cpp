#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<ll>a(n),b(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    b[0]=a[0];
    for(int i=1; i<n; ++i){
        b[i]=b[i-1]+a[i];
    }
    int ans=1;
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    for(int i=0; i<n-1; ++i){
        if(a[i]<=b[i+1]*2)ans++;
        else break;
    }
    cout<<ans<<endl;
}