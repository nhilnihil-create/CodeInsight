    #include<bits/stdc++.h>  
    using namespace std;  
    typedef long long LL;  
    const int maxn=1e5+10;  
    int n,d[maxn];  
    LL a[maxn];  
    vector<int> G[maxn];  
    bool flag=1;  
    void dfs(int u,int fu)  
    {  
        LL sum=0,maxs=0;  
        int o=0;  
        for (int i=0;i<G[u].size();i++)  
        {  
            int v=G[u][i];  
            if (v==fu) continue;  
            o++;  
            dfs(v,u);  
            sum+=a[v];  
            maxs=max(maxs,a[v]);  
        }  
        if (o==0) return ;  
        LL x=sum-a[u],y=2*a[u]-sum;  
        if (x<0||y<0||x>min(sum-maxs,sum/2)||(fu==-1&&y)) flag=0;  
        a[u]=y;  
    }  
    int main()  
    {  
        cin>>n;  
        for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);  
        for (int i=1;i<n;i++)  
        {  
            int u,v;scanf("%d%d",&u,&v);  
            G[u].push_back(v);G[v].push_back(u);  
            d[u]++;d[v]++;  
        }  
        int root=0;  
        for (int u=1;u<=n;u++) if (d[u]>1) {root=u;break;}  
        if (root) dfs(root,-1);  
        else flag=(a[1]==a[2]);  
        if (flag) cout<<"YES";  
        else cout<<"NO";  
        return 0;  
    }  