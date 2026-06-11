#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    ll n,sum=0,A[200001],B[200001];
    cin>>n;
    rep(i,n) cin>>A[i],sum+=A[i];
    if(sum%(n*(n+1)/2)){
        cout<<"NO";
        return 0;
    }
    ll d=sum/(n*(n+1)/2);
    rep(i,n-1) B[i]=A[i+1]-A[i];
    ll ans=0;
    rep(i,n-1){
        if(d<B[i]){
            cout<<"NO";
            return 0;
        }
        if((d-B[i])%n){
            cout<<"NO";
            return 0;
        }
        ans+=(d-B[i])/n;
    }
    if(ans>d){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
}