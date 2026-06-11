#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <bitset>
#include <iterator>	
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cassert>
#define INF 2000000000
#define MOD 1000000007
#define sym cout<<"---------"<<endl;
#define ll long long
#define mk make_pair
#define en endl
#define RE return 0
#define int ll
#define P pair<int,int>
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int gcd(int a,int b){if(a%b==0){return b;}else return gcd(b,a%b);}
int lcm(int a,int b){if(a==0){return b;} return a/gcd(a,b)*b;}

#define MAX 100005
int n, dist1[MAX], dist2[MAX], u[MAX], v[MAX];
vector<int> x[MAX];

void dfs1(int pos, int depth){
	if(dist1[pos]!=-1) return;
	dist1[pos]=depth;
	for(int i=0; i<x[pos].size(); i++){ 
		dfs1(x[pos][i], depth+1);
	}
}

void dfs2(int pos,int depth){
	if(dist2[pos]!=-1) return;
	dist2[pos]=depth;
	for(int i=0; i<x[pos].size(); i++){
		dfs2(x[pos][i], depth+1);
	}
}

signed main(){
	cin>>n;
	for(int i=0; i<n-1; i++){
		int a,b;
		cin>>a>>b;
		x[a].push_back(b);
		x[b].push_back(a);
	}
	for(int i=0; i<100003; i++){
		dist1[i]=-1;
		dist2[i]=-1;
	}
	dfs1(1, 0); dfs2(n, 0);
	int cnt1=0,cnt2=0;
	for(int i=1; i<=n; i++){
		if(dist1[i]<=dist2[i]) cnt1++;
		else cnt2++;
	}
	if(cnt1>cnt2) cout<<"Fennec"<<en;
	else cout<<"Snuke"<<en;
}
