#include <iostream>
#include <math.h>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <bitset>
#include <string.h>

using namespace std;

const int maxn=2005;

int n, k;
vector < int > ms[maxn];
bitset < maxn > bio;
queue < pair < int, int > > q;
int branch[maxn];
int zbroj[maxn];

void bfs(int x){
	pair < int, int > p;
	bio[x]=1;
	q.push({x, 0});
	while(!q.empty()){
		p=q.front();
		if(p.second==k/2){
			break;
		}
		q.pop();
		x=p.first;
		for(int i=0; i<ms[x].size(); i++){
			if(!bio[ms[x][i]]){
				if(!p.second){
					branch[ms[x][i]]=ms[x][i];
				}
				else{
					branch[ms[x][i]]=branch[x];
				}
				bio[ms[x][i]]=1;
				q.push({ms[x][i], p.second+1});
			}
		}
	}
}

int solve(int x){
	bfs(x);
	int br=bio.count();
	if(k%2){
		int maksi=0;
		while(!q.empty()){
			zbroj[branch[q.front().first]]+=ms[q.front().first].size()-1;
			maksi=max(maksi, zbroj[branch[q.front().first]]);
			q.pop();
		}
		br+=maksi;
	}
	return n-br;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	int a, b;
	for(int i=0; i<n-1; i++){
		cin >> a >> b;
		a--;
		b--;
		ms[a].push_back(b);
		ms[b].push_back(a);
	}
	if(k==1){
		cout << n-2 << '\n';
		return 0;
	}
	int sol=n;
	for(int i=0; i<n; i++){
		sol=min(sol, solve(i));
		while(!q.empty()){
			q.pop();
		}
		memset(zbroj, 0, sizeof(zbroj));
		bio.reset();
	}
	cout << sol << '\n';
	return 0;
}