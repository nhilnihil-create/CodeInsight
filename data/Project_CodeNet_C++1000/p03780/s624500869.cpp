#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    vector<vector<int>>dp1(n+1,vector<int>(k));
    vector<vector<int>>dp2(n+1,vector<int>(k));
    dp1[0][0]=1,dp2[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            dp1[i+1][j]=max(dp1[i+1][j],dp1[i][j]);
            if(j+a[i]<k)dp1[i+1][j+a[i]]=max(dp1[i+1][j+a[i]],dp1[i][j]);
            dp2[i+1][j]=max(dp2[i+1][j],dp2[i][j]);
            if(j+a[n-i-1]<k)dp2[i+1][j+a[n-i-1]]=max(dp2[i+1][j+a[n-i-1]],dp2[i][j]);
        }
    }
    int ans=n;
    for(int i=0;i<n;i++){
        vector<int>l;
        vector<int>r;
        for(int j=0;j<k;j++){
            if(dp1[i][j])l.push_back(j);
            if(dp2[n-i-1][j])r.push_back(j);
        }
        for(int j=0;j<l.size();j++){
            if(l[j]+r.back()>=k-a[i] && 
            *lower_bound(r.begin(),r.end(),k-a[i]-l[j])<k-l[j]){
                ans--;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}