#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[a[i]]==i) ans++;
    }
    cout<<ans/2<<"\n";
    return 0;
}