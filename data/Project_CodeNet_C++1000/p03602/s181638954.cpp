#include <bits/stdc++.h>

using namespace std;
vector<vector<int> >mtx,mtx3;
vector<int>vis;
int cnt=0;
int n;
void dfs(int i,int j,int tr,long long ttl=0ll){
    cnt++;
    vis[i]=1;
    if(ttl==(long long)mtx[j][i])
        mtx3[j][i]++;
    else{
        vis[i]=0;
        return ;
    }
    for(int k=0;k<n;k++){
        if(!vis[k]){
            dfs(k,j,tr,ttl+(long long)mtx[i][k]);
        }
    }
    vis[i]=0;
}
int main()
{
    ///{}
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    cin>>n;
    mtx=vector<vector<int> >(n,vector<int>(n));
    mtx3=mtx;
    long long ans=0ll;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mtx[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            ans+=(long long)mtx[i][j];
        }
    }
    vector<vector<int> >mtx2=mtx;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mtx2[i][j]=min(mtx2[i][j],mtx2[i][k]+mtx2[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mtx2[i][j]!=mtx[i][j]||mtx[i][j]!=mtx[j][i]){
                cout<<-1<<'\n';
                return 0;
            }
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(k==j||k==i)
                    continue;
                if(mtx[i][k]+mtx[k][j]==mtx[i][j]&&mtx3[i][j]==0){
                    ans-=(long long)mtx[i][j];
                    mtx3[i][j]=1;
                }
            }
        }
    }

    cout<<ans<<'\n';

    return 0;
}
/**
10
0 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1
1 1 0 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1
1 1 1 1 0 1 1 1 1 1
1 1 1 1 1 0 1 1 1 1
1 1 1 1 1 1 0 1 1 1
1 1 1 1 1 1 1 0 1 1
1 1 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1 0
*/
