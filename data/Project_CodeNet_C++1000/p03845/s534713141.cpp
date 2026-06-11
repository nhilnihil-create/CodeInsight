#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n;cin>>n;
    
    int t[n];
    int s=0;
    rep(i,n){
        cin>>t[i];
        s+=t[i];
    }
    
    int m;cin>>m;
    int p,x;
    
    rep(i,m){
        cin>>p>>x;
        int ans = s - t[p-1] + x;
        cout<<ans<<endl;
    }
    return 0;
}