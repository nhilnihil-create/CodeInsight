#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,k;const int SIZE=2050;
int w[SIZE];
int shk,fzy;
std::vector<int>v[SIZE];
int d[SIZE];
int e[SIZE][2];
int vis[SIZE];
void init(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
}
void init2(){
	init();
	for(int i=1;i<=n;i++){
		d[i]=0;
	}
}
void dfs(int pos,int deep){
	d[pos]+=deep;vis[pos]=1;
	//cout<<"pos="<<pos<<endl;
	for(int i=0;i<v[pos].size();i++){
		//cout<<"next:"<<v[pos][i]<<endl;
		if(!vis[v[pos][i]])
			dfs(v[pos][i],deep+1);
	}
}

void display(){
	for(int i=1;i<=n;i++)
		cout<<"i="<<i<<" d[i]="<<d[i]<<endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n-1;i++){
		cin>>shk>>fzy;
		v[shk].push_back(fzy);v[fzy].push_back(shk);
		e[i][0]=shk;e[i][1]=fzy;
	}
	int ans=n;
	if(k%2==0){//k为偶数
		for(int i=1;i<=n;i++){
			init2();
			dfs(i,0);
			int cnt=0;
			//display();
			for(int j=1;j<=n;j++){
				if(d[j]>k/2)cnt++;
			}
			ans=min(ans,cnt);
		}
	}
	else{
		for(int i=1;i<=n-1;i++){
			init2();
			dfs(e[i][0],0);
			init();
			dfs(e[i][1],0);
			int cnt=0;//cout<<"ddsa"<<endl;
			for(int j=1;j<=n;j++){
				if(d[j]>k)cnt++;
			}
			ans=min(ans,cnt);
		}
	}
	cout<<ans<<endl;
}