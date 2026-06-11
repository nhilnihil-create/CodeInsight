#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[m],b[m],c[m];
    vector<vector<int>>d(n,vector<int>(n,1000000000));
    for(int i=0;i<n;i++)d[i][i]=0;
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;
        b[i]--;
        d[a[i]][b[i]]=c[i];
        d[b[i]][a[i]]=c[i];
    }
    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)d[i][j]=min(d[i][j],d[i][k]+d[j][k]);
    bool use[m]={};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(d[j][k]==d[j][a[i]]+c[i]+d[b[i]][k] || d[j][k]==d[j][b[i]]+c[i]+d[a[i]][k]){
                    use[i]=1;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<m;i++)if(use[i]==0)ans++;
    cout<<ans<<endl;
    return 0;
}