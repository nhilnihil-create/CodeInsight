#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;


int n,m,i,x,y,vis[100005],lst;
vector<int> e[100005];
deque<int> dq;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,m){
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x); 
	}
	dq.push_back(1);
	dq.push_back(e[1][0]);
	vis[1]=vis[e[1][0]]=1;
	lst=1;
	for(;;){
		for(i=0;i<e[lst].size();i++){
			if(!vis[e[lst][i]]){
				dq.push_front(e[lst][i]);
				vis[e[lst][i]]=1;
				break;
			}
		}
		if(i<e[lst].size()) lst=e[lst][i]; else break;
	}
	lst=e[1][0];
	for(;;){
		for(i=0;i<e[lst].size();i++){
			if(!vis[e[lst][i]]){
				dq.push_back(e[lst][i]);
				vis[e[lst][i]]=1;
				break;
			}
		}
		if(i<e[lst].size()) lst=e[lst][i]; else break;
	}
	cout<<dq.size()<<endl;
	for(i=0;i<dq.size();i++) cout<<dq[i]<<' ';
	return 0;
}