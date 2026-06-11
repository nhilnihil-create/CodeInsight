#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#include <string>
#define SIZE 100005
#define INF 1000000005LL
#define INFTY 100000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct Node{int p,rs,lc;};

ll K;
int n,d1[SIZE],dn[SIZE];
Node T[SIZE];
set<int> G[SIZE];
int cnt;

void bfs(int s,int d[]){
	queue<int> q;
	q.push(s);
	cnt=0;
	for(int i=1;i<=n;i++)d[i]=INFTY;
	d[s]=0;
	int u;
	while(!q.empty()){
		u = q.front();q.pop();
		cnt++;
		for(set<int>::iterator it=G[u].begin();it!=G[u].end();it++){
			if(d[*it]!=INFTY)continue;
			d[*it]=d[u]+1;
			q.push(*it);
		}
	}
}

int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=0;i<(n-1);i++){
		scanf("%d %d",&x,&y);
		G[x].insert(y);
		G[y].insert(x);
	}

	bfs(1,d1);
	bfs(n,dn);
	int minv = 9999999;
	int mid;

	if(d1[n]%2==0){
		for(int i=1;i<=n;i++){
			if(d1[i]==dn[i] && d1[i]<minv){
				mid = i;
				minv = d1[i];
			}
		}
		for(set<int>::iterator it=G[mid].begin();it!=G[mid].end();it++){
			if(dn[*it] == minv-1){
				G[mid].erase(*it);
				G[*it].erase(mid);
				break;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(abs(d1[i]-dn[i])==1 && d1[i]<minv){
				mid = i;
				minv = d1[i];
			}
		}
		for(set<int>::iterator it=G[mid].begin();it!=G[mid].end();it++){
			if(dn[*it] == minv){
				G[mid].erase(*it);
				G[*it].erase(mid);
				break;
			}
		}
	}
	//cut
	
	bfs(1,d1);
	//printf("(%d)",cnt);
	if(cnt>n/2)printf("Fennec\n");
	else printf("Snuke\n");

	return 0;
}
