#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool ldp[n][k]={},rdp[n][k]={};
    ldp[0][0]=rdp[0][0]=true;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<k;j++){
            ldp[i+1][j]|=ldp[i][j];
            rdp[i+1][j]|=rdp[i][j];
            if(ldp[i][j]&&j+a[i]<k)ldp[i+1][j+a[i]]=true;
            if(rdp[i][j]&&j+a[n-i-1]<k)rdp[i+1][j+a[n-i-1]]=true;
        }
    }
    int ans=n;
    for(int i=0;i<n;i++){
        int r=k-1;
        bool flag=false;
        for(int l=0;l<k;l++){
            if(ldp[i][l]){
                while(k<=l+r)r--;
                while(max(k-a[i],0)<=l+r){
                    if(rdp[n-i-1][r]){
                        flag=true;
                        break;
                    }
                    else r--;
                }
            }
        }
        if(flag)ans--;
    }
    cout<<ans<<endl;
}
