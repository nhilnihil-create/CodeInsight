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
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int n;
	int k;
	scanf("%d %d", &n, &k);
	int a[100000];
	int ans=0;
	vector<int> v[100000];
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		a[i]--;
		if(i>0){
			v[a[i]].push_back(i);
		}else{
			if(a[0]!=0){
				ans++;
				a[0]=0;
			}
		}
	}
	int d[100000];
	d[0]=0;
	queue<int> que;
	que.push(0);
	while(!que.empty()){
		int x=que.front();
		que.pop();
		for(int i=0; i<v[x].size(); i++){
			d[v[x][i]]=d[x]+1;
			que.push(v[x][i]);
		}
	}
	vector<P> dist;
	for(int i=0; i<n; i++){
		dist.push_back(P(d[i], i));
	}
	bool ok[100000]={};
	sort(dist.begin(), dist.end(), greater<P>());
	for(int i=0; i<n; i++){
		int x=dist[i].second;
		if(d[x]<=k) continue;
		if(ok[x]==1) continue;
		bool e=0;
		for(int j=0; j<k; j++){
			if(ok[x]==1){
				e=1;
				break;
			}
			ok[x]=1;
			x=a[x];
		}
		if(e==0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}