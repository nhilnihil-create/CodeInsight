#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    long long a[n],sum[n+1]={},msum[n+1]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum[i+1]+=sum[i]+max((long long)0,a[i]);
        msum[i+1]+=msum[i]+min((long long)0,a[i]);
    }
    long long t=-1e18,r=0;
    for(int i=0;i<k;i++){
        r+=a[i];
    }
    if(r>=0) t=max(t,msum[k]);
    else{
        t=max(t,-sum[k]);
    }
    for(int i=k;i<n;i++){
        r-=a[i-k];
        r+=a[i];
        if(r>=0) t=max(t,msum[i+1]-msum[i-k+1]);
        else{
            t=max(t,-sum[i+1]+sum[i-k+1]);
        }
    }
    cerr<<sum[n]<<" "<<t<<endl;
    cout<<sum[n]+t;
    
}