#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll n,m;
vector<int> G[100001];
int color[100001];
ll cnt=0;
bool f;

bool dfs(int v,int c){
	color[v]=c;
	cnt++;
	for(int i=0;i<G[v].size();i++){
		if(color[G[v][i]]==c)f=false;
		if(color[G[v][i]]==0 && !dfs(G[v][i],-c))f=false;
	}
	return f;
}

int main(void){
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<m;i++){
		int f,t;
		scanf("%d%d",&f,&t);
		f--;
		t--;
		G[f].push_back(t);
		G[t].push_back(f);
	}
	memset(color,0,sizeof(color));
	ll res=0,one=0,two=0,other=0;
	for(int i=0;i<n;i++){
		if(color[i]==0){
			cnt=0;
			f=true;
			dfs(i,1);
			if(cnt==1)one++;
			if(f && cnt>1)two++;
			if(!f && cnt>1)other++;
		}
	}
	res=(one*one)+(2LL*one*(n-one));
	res+=(2LL*two*two)+(2LL*two*other)+other*other;
	printf("%lld\n",res);
	return 0;
}
