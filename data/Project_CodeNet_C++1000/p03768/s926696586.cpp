/******************
*  Author: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int cl[100005];
int lst[100005];
vector<int> eds[100005];
int n,m,q;

void dfs1(int v,int d,int c){
	if(!cl[v])
		cl[v]=c;
	if(lst[v]>=d)
		return;
	lst[v]=d;
	if(d==0)
		return;
	for(int u=0;u<eds[v].size();u++)
		dfs1(eds[v][u],d-1,c);
}

vector<int> vv,dd,cc;

int main(){

	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a;--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	cin>>q;
	for(int i=0;i<q;i++){
		int v,d,c;
		cin>>v>>d>>c;
		--v;
		vv.push_back(v);
		dd.push_back(d);
		cc.push_back(c);
	}
	reverse(vv.begin(),vv.end());
	reverse(dd.begin(),dd.end());
	reverse(cc.begin(),cc.end());
	for(int i=0;i<q;i++){
		int v,d,c;
		v=vv[i];
		d=dd[i];
		c=cc[i];
		dfs1(v,d,c);
	}
	for(int i=0;i<n;i++){
		cout<<cl[i]<<endl;
	}

	return 0;
}
