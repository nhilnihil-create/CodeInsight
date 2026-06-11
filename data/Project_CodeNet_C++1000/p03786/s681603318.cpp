#include <bits/stdc++.h>
#include<utility>
#include<algorithm>

#define pan(i,n) for(int i=0;i<n;i++)
#define pans(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define INF 1e9+7
#define PI 3.141592653
#define inf 200007
#define P pair<ll,ll>

using namespace std;

int main(){
    int n,ans=0;
    cin>>n;
    vl a(n);
    pan(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    int count=0;
    ll sum=0,presum=0;
    vl psum(n);
    psum[0]=a[0];
    pans(i,n,1) psum[i]=a[i]+psum[i-1];
    for(int i=0;i<n-1;i++){
        if(2*psum[i]>=a[i+1]){
            count++;
        }
        else {
            count=0;
        }
        // cout<<count<<" "<<psum<<endl;
    }
    ans=count+1;
    cout<<ans;
}   