#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#include<bitset>
#include<iomanip>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int main(){
	int N,M;
	vint adj[100001];
	scan(N);scan(M);
	rep(i,M){
		int a,b;
		scan(a);scan(b);
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	deque<int> path;
	bool pathexist[100001]={};
	path.push_front(0),path.push_back(adj[0][0]);
	pathexist[0]=pathexist[adj[0][0]]=true;
	while(1){
		int flag=1;
		int fr=path.front(),ba=path.back();
		rep(i,adj[fr].size()){
			if(pathexist[adj[fr][i]]==false){
				flag=0;
				path.push_front(adj[fr][i]);
				pathexist[adj[fr][i]]=true;
				break;
			}
		}
		if(flag==0) continue;
		rep(i,adj[ba].size()){
			if(pathexist[adj[ba][i]]==false){
				flag=0;
				path.push_back(adj[ba][i]);
				pathexist[adj[ba][i]]=true;
				break;
			}
		}
		if(flag==0) continue;
		else break;
	}
	prin(path.size());
	rep(i,path.size()){
		printf("%d ",path[i]+1);
	}
	kaigyo;
	return 0;
}
