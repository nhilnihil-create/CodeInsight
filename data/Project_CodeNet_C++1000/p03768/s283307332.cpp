#include<bits/stdc++.h>

using namespace std;
int cl[100005],lst[100005];
vector<int>est[100005];
int v[100005],d[100005],c[100005];
int n,m,q; 
void dfs(int v,int d,int c){
	if(!cl[v])cl[v]=c;
	if(lst[v]>=d)return;
	lst[v]=d;
	if(d==0)return;
	for(int i=0;i<est[v].size();i++)dfs(est[v][i],d-1,c);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		est[a].push_back(b);
		est[b].push_back(a);
	} 
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>v[i]>>d[i]>>c[i];
	}	
	for(int i=q;i>=0;i--)dfs(v[i]-1,d[i],c[i]);
	for(int i=0;i<n;i++)cout<<cl[i]<<endl;
	return 0;
}