/******************
*  Author: BD747  *
******************/
//Endagorion
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

const int maxn=100005,maxd=11;
int c[maxn][maxd];
int col[maxn];
vector<int> e[maxn];

int main(){

	int n,m,q;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a;--b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	cin>>q;
	for(int i=0;i<q;i++){
		int v,d;
		cin>>v>>d>>col[i+1];
		--v;
		c[v][d]=i+1;
	}
	for(int i=maxd-2;i>=0;i--){
		for(int v=0;v<n;v++){
			for(int u=0;u<e[v].size();u++){
				c[e[v][u]][i]=max(c[e[v][u]][i],c[v][i+1]);
			}
		}
	}
	
	for(int v=0;v<n;v++){
		int res=0;
		for(int d=0;d<maxd;d++){
			res=max(res,c[v][d]);
		}
		cout<<col[res]<<endl;
	}

	return 0;
}
