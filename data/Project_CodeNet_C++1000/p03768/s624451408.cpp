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
int n,m,cnt,tot,fst[100004],pnt[100004<<1],nxt[100004<<1],ans[100004],dp[100004][12];
void add(int x,int y){
	pnt[++tot]=y;
	nxt[tot]=fst[x];
	fst[x]=tot;
}
int main(){
	cin>>n>>m;
	int i,j,x,y;
	for (i=1;i<=m;i++){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	cin>>cnt;
	for (i=1;i<=cnt;i++){
		cin>>x>>y>>ans[i];
		dp[x][y]=i;
	}
	for (i=9;i>=0;i--)
		for (x=1;x<=n;x++){
			dp[x][i]=max(dp[x][i],dp[x][i+1]);
			for (j=fst[x];j;j=nxt[j])
				dp[x][i]=max(dp[x][i],dp[pnt[j]][i+1]);
			}
	for (i=1;i<=n;i++) cout<<ans[dp[i][0]]<<endl;
	return 0;
}