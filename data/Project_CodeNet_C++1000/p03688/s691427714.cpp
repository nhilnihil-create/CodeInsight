#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rept(k,i,n) for(int i = (k); i < (int)(n); i++)


int main(){
    int n; cin>>n;
    vector<int> a(n);
    int mi=10000000,ma=0;
    rep(i,n){
        cin>>a[i];
        mi=min(mi,a[i]);
        ma=max(ma,a[i]);
    }
    if(ma-mi>=2) cout<<"No";
    else if(ma==mi){
        if(ma==n-1|| ma*2<=n) cout<<"Yes";
        else cout<<"No";
    }
    else{
        int k=0,l;
        rep(i,n) if(a[i]==ma) k++;
        l=n-k;
        if(l<ma&&(ma-l)*2<=k) cout<<"Yes";
        else cout<<"No";
    }
    return 0;
}