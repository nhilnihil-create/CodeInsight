#include<bits/stdc++.h>
using namespace std;
queue<int>q;
vector<int>v[100003];
int dis[2][100003],n,a,b;
void bfs(int x){
	q.push(x*(n-1));
	dis[x][x*(n-1)]=1;
	while(!q.empty()){
		int f=q.front();
		q.pop();
		for(int i=0;i<v[f].size();i++)
			if(!dis[x][v[f][i]])
				dis[x][v[f][i]]=dis[x][f]+1,
				q.push(v[f][i]);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	bfs(0);bfs(1);
	a=0;b=0;
	for(int i=0;i<n;i++)
		if(dis[0][i]>dis[1][i])
			b++;
		else
			a++;
	if(a>b)
		cout<<"Fennec";
	else
		cout<<"Snuke";
}