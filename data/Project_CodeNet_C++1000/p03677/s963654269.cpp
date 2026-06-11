#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
ll int MOD=998244353;
#define N 110000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    ll int n,m,a[N],count[N]={};
    cin>>n>>m;
    rep(i,n) cin>>a[i];
    ll int temp=0;
    rep(i,n-1){
        if(a[i]>a[i+1]) temp+=a[i+1];
        else temp+=-a[i]+a[i+1];
    }
    rep2(i,1,n-1){
        count[a[i]]+=(m+a[i]-a[i-1])%m;
    }
    ll int r[N]={};
    rep(i,n-1){
        if(a[i]>a[i+1]){
            r[a[i]+1]++;
            r[0]++;
            r[a[i+1]+1]--;
        }
        else{
            r[a[i]+1]++; r[a[i+1]+1]--;
        }
    }
    rep2(i,1,m){
        r[i]=r[i]+r[i-1];
    }
    rep2(i,1,m){
        r[i]=count[i]-r[i];
    }
    ll int ans=temp;
    rep2(i,1,m-1){
        temp+=r[i];
        ans=min(ans,temp);
    }
    cout<<ans;
    return 0;
}