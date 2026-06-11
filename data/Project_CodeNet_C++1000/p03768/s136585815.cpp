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
int cl[120000];
int lst[120000];
vector <int> eds[120000];
int n,m,q;
void dfs(int v,int d,int c){
	if (!cl[v]) cl[v]=c;
	if (lst[v]>=d) return;
	lst[v]=d;
	if (d==0) return;
	for (int u: eds[v])
		dfs(u,d-1,c);
}
vector <tuple<int,int,int> > vv;
int main(){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a,--b;
		eds[a].push_back(b);
		eds[b].push_back(a);  
	}
	cin>>q;
	for (int i=0;i<q;i++){
		int v,d,c;
		cin>>v>>d>>c;
		--v;
		vv.push_back(make_tuple(v,d,c)); 
	}
	reverse (vv.begin(),vv.end());
	for (int i=0;i<q;i++){
		int v,d,c;
		tie(v,d,c)=vv[i];
		dfs(v,d,c);
	}
	for (int i=0;i<n;i++) cout<<cl[i]<<endl;
	return 0;
}