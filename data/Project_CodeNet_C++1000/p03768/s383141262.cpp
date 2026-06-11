#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int N,M,Q;
vector <int> g[100004];
int col[100004],turns[100004];
bool vis[100004];
void bfs(int v,int d,int c){
	memset (vis,0,sizeof(vis));
	queue <pii> q;
	q.push(pii(v,0));
	while (!q.empty()){
		int x=q.front().first,dist=q.front().second;
		q.pop();
		if (d-dist<=turns[x]) continue;
		turns[x]=d-dist; 
		if (dist>d) continue;
		if (vis[x]) continue;
		vis[x]=1;
		if (col[x]==0) col[x]=c;
		for (int i=0;i<g[x].size();i++)
			q.push(pii(g[x][i],dist+1)); 
	}
}
int v[100004],d[100004],c[100004];
int main(){
	memset (col,0,sizeof(col));
	memset (turns,-1,sizeof(turns));
	cin>>N>>M;
	for (int i=0;i<M;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cin>>Q;
	for (int i=0;i<Q;i++){
		cin>>v[i]>>d[i]>>c[i];
	}
	for (int i=Q-1;i>=0;i--)
		bfs(v[i],d[i],c[i]);
	for (int i=1;i<=N;i++)
		cout<<col[i]<<endl;
	return 0;
}