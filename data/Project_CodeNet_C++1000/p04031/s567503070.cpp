#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n) cin>>a[i];
    ll ans=1000100001;
    for(int i=-100;i<101;i++){
        ll cnt=0;
        rep(j,n){
            int temp=pow(a[j]-i,2);
            cnt+=temp;
        }
        ans=min(cnt,ans);
    }
    cout<<ans<<endl;
}