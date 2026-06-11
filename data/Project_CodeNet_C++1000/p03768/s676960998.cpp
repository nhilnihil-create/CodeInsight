    #include<bits/stdc++.h>
    using namespace std;
    int ans[100003],n,m,q,do1[100003],do2[100003],do3[100003];
    vector<int>v[100005];
    int vis[100003];
    void dfs(int a,int b,int c){
    	if(b==-1)return;
    	if(b<=vis[a])return;
    	vis[a]=b;
    	if(!ans[a])ans[a]=c;
    	for(int i=0;i<v[a].size();i++)
    		dfs(v[a][i],b-1,c);
    }
    int main(){
    	cin>>n>>m;
    	for(int i=0;i<=100002;i++)vis[i]=-1;
    	for(int i=0;i<m;i++)
    	{
    		int a,b;
    		cin>>a>>b;
    		v[a].push_back(b);
    		v[b].push_back(a);
    	}
    	cin>>q;
    	for(int i=1;i<=q;i++)
    		cin>>do1[i]>>do2[i]>>do3[i];
    	for(int i=q;i>0;i--){
    		dfs(do1[i],do2[i],do3[i]);
    	}
    	for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
    }