#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    ll n,k,A[200001],sum=0;
    cin>>n>>k;
    rep(i,n){
        cin>>A[i];
        if(A[i]>0) sum+=A[i];
    }
    ll m=1e18,a=0,b=0;
    rep(i,n-k+1){
        if(i==0) rep(j,k) a+=A[j]*(A[j]<0),b+=A[j]*(A[j]>0);
        else{
            a=a-A[i-1]*(A[i-1]<0)+A[i+k-1]*(A[i+k-1]<0);
            b=b-A[i-1]*(A[i-1]>0)+A[i+k-1]*(A[i+k-1]>0);
        }
        m=min({m,-a,b});
    }
    cout<<sum-m;
}