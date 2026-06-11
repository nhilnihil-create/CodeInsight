#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
vector<int> g[100010];
int dist1[100010],dist2[100010];
bool used1[100010],used2[100010];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a); 
	}
	queue<int> q;
	q.push(1);
	used1[1]=true;dist1[1]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<g[x].size();i++){
			if(!used1[g[x][i]]){
				q.push(g[x][i]);
				dist1[g[x][i]]=dist1[x]+1;
				used1[g[x][i]]=true;
			}
		}
	}
	q.push(n);
	used2[n]=true;dist2[n]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<g[x].size();i++){
			if(!used2[g[x][i]]){
				q.push(g[x][i]);
				dist2[g[x][i]]=dist2[x]+1;
				used2[g[x][i]]=true;
			}
		}
	}
	int snuke=0,fennec=0;
	for(int i=1;i<=n;i++){
		//cout<<i<<" "<<dist1[i]<<" "<<dist2[i]<<endl;
		if(dist1[i]>dist2[i])snuke++;
		if(dist2[i]>=dist1[i])fennec++;
	}
	if(fennec>snuke)cout<<"Fennec";
	else cout<<"Snuke";
	return 0;
}