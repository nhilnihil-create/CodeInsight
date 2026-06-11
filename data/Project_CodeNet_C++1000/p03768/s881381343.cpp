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
int n,m,q,mindist[100004],col[100004],s[100004],d[100004],c[100004];
vector <int> g[100004];
void dfs(int x,int dist,int color){
	if (dist<=mindist[x]) return;
	mindist[x]=dist;
	if (col[x]==0) col[x]=color;
	for (int i=0;i<g[x].size();i++)
		dfs(g[x][i],dist-1,color);
}
int main(){
	memset (col,0,sizeof(col));
	memset (mindist,-1,sizeof(mindist));
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	cin>>q;
	for (int i=0;i<q;i++)
		cin>>s[i]>>d[i]>>c[i];
	for (int i=q-1;i>=0;i--)
		dfs(s[i],d[i],c[i]);
	for (int i=1;i<=n;i++)
		cout<<col[i]<<"\n";
	return 0;
}