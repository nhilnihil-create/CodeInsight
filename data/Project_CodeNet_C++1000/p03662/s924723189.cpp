#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
typedef long long int ll;

int n;
int used[110100];
int used2[110100];
int de[110100];
int de2[110100];
vector<int> G[100100];

void dfs(int s,int t,int depth){
	if(s==t){
		return;
	}
	used[s]=1;
	de[s]=depth;
	for(int v:G[s]){
		if(!used[v]){
			dfs(v,t,depth+1);
		}
	}
	return;
}

void dfs2(int s,int t,int depth){
	if(s==t){
		return;
	}
	used2[s]=1;
	de2[s]=depth;
	for(int v:G[s]){
		if(!used2[v]){
			dfs2(v,t,depth+1);
		}
	}
	return;
}

int main(){
	int n; cin >> n;
	for(int i=0;i<n-1;i++){
		int x,y; cin >> x >> y;
		x--; y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(0,n-1,1);
	dfs2(n-1,0,1);
	int black=0;
	for(int i=0;i<n;i++){
		if(used2[i]==0)black++;
		else{
			if(de[i]>0&&de[i]<=de2[i])black++;
		}
	}
	if(black>n-black){
		cout << "Fennec" << endl;
	}
	else{
		cout << "Snuke" << endl;
	}
}