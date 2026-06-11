#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a,b,L,c,tmp,ans,dp[2000][2000],rans=1e15;
vector<ll> v;
int main(void){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
        dp[i][0]=a;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=min(dp[i][j-1],v[(i+j)%n]);
        }
    }
    for(int i=0;i<n;i++){
        ans=0;
        for(int j=0;j<n;j++){
            ans+=dp[j][i];
            //cout<<dp[j][i]<<" ";
        }
        //cout<<endl;
        ans+=k*i;
        rans=min(ans,rans);
    }
    cout<<rans<<endl;
}
