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
vector <int> g[100003];
int vis[100003];
int main() {
	int n;
	cin>>n;
	for (int i=0; i<n-1; i++) {
		int x,y;
		cin>>x>>y;
		  g[x].push_back(y);
		g[y].push_back(x);
	}
	queue <int> q;
	q.push(1),q.push(n);
	memset (vis,-1,sizeof(vis));
	vis[1]=0;
	vis[n]=1;
	while (!q.empty()) {
		int x=q.front();
		q.pop();
		for (int i=0; i<g[x].size(); i++) {
			if (vis[g[x][i]]==-1) {
				vis[g[x][i]]=vis[x];
				q.push(g[x][i]);
			}
		}
	}
	int cnt1=0,cnt2=0;
	for (int i=1;i<=n;i++){
		if (vis[i]==0) cnt1++;
		else cnt2++;
	}
	if (cnt1>cnt2) cout<<"Fennec";
	else cout<<"Snuke";
	return 0;
}