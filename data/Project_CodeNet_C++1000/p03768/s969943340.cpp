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
#define vi vector<int>
#define forn(i,n) for(int i=0;i<(int)(n);++i)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;--i) 
const int maxn=110000,maxd=11;
int c[maxn][maxd];
int col[maxn];
template<class T>bool uin(T &a,T &b){
	return a>b?(a=b,true):false;
}
template<class T>bool uax(T &a,T &b){
	return a<b?(a=b,true):false;
}
vi e[maxn];
int main(){
	int n,m,q;
	cin>>n>>m;
	forn(i,m){
		int a,b;
		cin>>a>>b;
		--a,--b;
		e[a].push_back(b);
		e[b].push_back(a);  
	}
	cin>>q;
	forn(i,q){
		int v,d;
		cin>>v>>d>>col[i+1];
		--v;
		c[v][d]=i+1;
	}
	ford(i,maxd-1) forn(v,n) for(int u:e[v]){
		uax(c[u][i],c[v][i+1]);
	}
	forn(v,n){
		int res=0;
		forn(d,maxd)
			uax(res,c[v][d]);
		cout<<col[res]<<endl;
	}
}