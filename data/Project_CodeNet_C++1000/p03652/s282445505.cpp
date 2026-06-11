#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
	int n,m;
	int a[305][305];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
		a[i][m+1]=0;
	}
	
	bool used[305];
	int cnt[305]={};
	int loc[305]={};
	priority_queue<P> que;
	for(int i=1;i<=n;i++){
		used[i]=false;
		cnt[a[i][1]]++;
		que.push(P(cnt[a[i][1]],a[i][1]));
		loc[i]=1;
	}
	int ret=n;
	used[0]=false;
	while(!que.empty()){
		P p=que.top(); que.pop();
		if(p.sc==0)break;
		if(used[p.sc])continue;
		used[p.sc]=true;
		chmin(ret,p.fr);
		for(int i=1;i<=n;i++){
			if(a[i][loc[i]]==p.sc){
				while(used[a[i][loc[i]]])loc[i]++;
				cnt[a[i][loc[i]]]++;
				que.push(P(cnt[a[i][loc[i]]],a[i][loc[i]]));
			}
		}
	}
	cout<<ret<<endl;
}
