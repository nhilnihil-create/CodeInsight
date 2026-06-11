#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
using namespace std;
const int N = 1e5+10;
int a[N];
vector<int> vec[N];
bool mark[N];
int dfs(int v,int p){
    mark[v]=1;
    int tot=0,ch=0,maxx=0;
    for(int u:vec[v]){
        if(mark[u])
            continue;
        ch++;
        int t=dfs(u,v);
        tot+=t;
        maxx=max(maxx,t);
    }
    if(ch==0)
        return a[v];
    if(a[v]>tot||a[v]<maxx||a[v]*2<tot){
        cout<<"NO";
        exit(0);
    }
    return 2*a[v]-tot;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++){
       int a,b;cin>>a>>b;
       vec[a].pb(b);
       vec[b].pb(a);
    }
    if(n==2){
        if(a[1]==a[2])
            cout<<"YES";
        else
            cout<<"NO";
        return 0;
    }
    int v=1;
    for(;v<=n;v++)
        if(vec[v].size()>=2)
            break;
    int ans=dfs(v,-1);
    if(ans==0)
        cout<<"YES";
    else
        cout<<"NO";
}


