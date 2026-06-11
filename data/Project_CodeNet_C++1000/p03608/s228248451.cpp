#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int>adj[100005];
std::vector<pair<int,pair<int,int>>>edges ;
bool vis[100005];
int costs[1003][1003];
int32_t main(){
    int n,m,r;
    cin>>n>>m>>r;
    int arr[r];
    for(int i=0;i<r;i++)cin>>arr[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)costs[i][j]=0;
            else costs[i][j]=100000000444;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        costs[a][b]=c,costs[b][a]=c;
    }
    int N=n;
     for(int k=1;k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                costs[i][j] = min(costs[i][j], costs[i][k]+costs[k][j]);
            }
        }
    }
    sort(arr,arr+r);
    int ans=1e18+7;
    do{
        int d=0;
        for(int i=0;i<r-1;i++){
            d+=costs[arr[i]][arr[i+1]];
        }
        ans=min(ans,d);
    }while(next_permutation(arr,arr+r));
    cout<<ans<<endl;
  return 0;
}