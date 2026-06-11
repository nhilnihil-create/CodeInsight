#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> v[100000];
	scanf("%d", &n);
	for(int i=0; i<n-1; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int d[100000];
	fill(d, d+n, -1);
	d[0]=0;
	queue<int> que;
	que.push(0);
	while(!que.empty()){
		int x=que.front();
		que.pop();
		for(int i=0; i<v[x].size(); i++){
			if(d[v[x][i]]==-1){
				d[v[x][i]]=d[x]+1;
				que.push(v[x][i]);
			}
		}
	}
	multimap<int, int> mp;
	for(int i=0; i<n; i++){
		mp.insert(make_pair(-d[i], i));
	}
	int g[100000];
	for(auto itr=mp.begin(); itr!=mp.end(); itr++){
		int x=itr->second;
		g[x]=0;
		for(int i=0; i<v[x].size(); i++){
			if(d[v[x][i]]>d[x]){
				g[x]=g[x]^(g[v[x][i]]+1);
			}
		}
	}
	if(g[0]==0){
		printf("%s\n", "Bob");
	}else{
		printf("%s\n", "Alice");
	}
	return 0;
}