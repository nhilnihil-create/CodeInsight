/*.....Bismillahir Rahmanir Rahim.....*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld long double
#define   pb push_back
#define   sz(x)  (int)x.size()
#define   ff first
#define   ss second
#define   pii  pair<int,int> 
#define   pb  push_back
#define   eb  emplace_back
#define   lcm(a,b)  (a*b)/gcd(a,b)
using namespace std;

const int inf=10000000;
signed main(){
	int n,m;
	cin>>n>>m;
	int a[1000],b[1000],c[1000],dist[1000][1000];	
	for(int i=0;i<m;++i){
		cin>>a[i]>>b[i]>>c[i];
		a[i]--,b[i]--;
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(i==j) dist[i][j]=0;
			else dist[i][j]=inf;
		}
	}
	for(int i=0;i<m;++i){
		dist[a[i]][b[i]]=min(dist[a[i]][b[i]],c[i]);			dist[b[i]][a[i]]=min(dist[b[i]][a[i]],c[i]);
	}
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	int ans=m;
	for(int i=0;i<m;++i){
		bool shortest=false;
		for(int j=0;j<n;++j)
			if(dist[j][a[i]]+c[i]==dist[j][b[i]])
				shortest=true;										if(shortest==true){
			ans--;
		}
	}
	cout<<ans<<endl;
}