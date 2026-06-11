#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#define NDEBUG
#include <assert.h>
using namespace std;
const int INF=INT_MAX/4;
/*
Status:Writing
Type:Problemset/HB
Problem ID:Atcoder ARC B
Author:XIZCM
*/
int n,a,b;
vector<int> nei[100005];
//int dis[100005],rdis[100005];
vector<int> bfs(int start){
	vector<int> d(n,INF);
	d[start]=0;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=0;i<nei[t].size();i++){
			int u=nei[t][i];
			if(d[u]>d[t]+1){
				d[u]=d[t]+1;
				q.push(u);
			}
		}
	}
	return d;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&a,&b);
		a--;
		b--;
		nei[a].push_back(b);
		nei[b].push_back(a);
	}
	vector<int> dis=bfs(0);
	vector<int> rdis=bfs(n-1);
	int s=0,f=0;
	for(int i=0;i<n;i++){
		if(dis[i]>rdis[i]){
			s++;
		}
		else{
			f++;
		}
	}
	puts(f>s?"Fennec":"Snuke");
	return 0;
}
