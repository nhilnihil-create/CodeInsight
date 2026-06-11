#include <bits/stdc++.h>
#define int long long
#define inf 1e9
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,a,b;
int ans1,ans2;
vector<int>vec[100005];
int whi[100005];
int fed[100005],sud[100005];
void bfs(){
	queue<int>quefe,quesu;
	quefe.push(0),quesu.push(n-1);
	fill(fed,fed+n,inf);
	fed[0]=0;
	while(quefe.size()){
		int fe=quefe.front();quefe.pop();
		rep(i,vec[fe].size()){
			if(fed[vec[fe][i]]==inf){
			   fed[vec[fe][i]]=fed[fe]+1;
			   quefe.push(vec[fe][i]);
		    }
		}
	}
	fill(sud,sud+n,inf);
	sud[n-1]=0;
	while(quesu.size()){
		int su=quesu.front();quesu.pop();
		rep(i,vec[su].size()){
			if(sud[vec[su][i]]==inf){
				sud[vec[su][i]]=sud[su]+1;
		        quesu.push(vec[su][i]);
			}
		}
	}
	rep(i,n){
		if(fed[i]<=sud[i])ans1++;
		else ans2++;
	}
	if(ans1>ans2)cout<<"Fennec"<<endl;
	else cout<<"Snuke"<<endl;
}
signed main(){
	cin>>n;
	rep(i,n-1){
		cin>>a>>b;
		vec[a-1].push_back(b-1);
		vec[b-1].push_back(a-1);
	}
	whi[0]=1,whi[n-1]=-1;
	bfs();
}

