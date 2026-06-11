
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n' 


llo n,m;
llo val[100001];
vector<llo> adj[100001];
llo ss=0;
llo st=1;
void dfs(llo no,llo val2=1){
	val[no]=val2;
	ss+=1;
	for(auto j:adj[no]){
		if(val[j]==0){
			dfs(j,3-val2);
		}
		else{
			if(val[j]==val[no]){
				st=0;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(llo i=0;i<m;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	llo x=0;
	llo y=0;
	llo ans=0;
	llo coo=0;
	for(llo i=0;i<n;i++){
		if(val[i]==0){
			ss=0;
			st=1;
			dfs(i);
			if(ss==1){
				//ans+=2*n-1;
				coo+=1;
			}
			else{
				if(st){
					y+=1;
				}
				else{
					x+=1;
				}
			}
		}
	}
	if(coo>0){
		ans+=(n-coo)*2*coo;
		ans+=coo*coo;
	}
	ans+=x*x+2*x*y+2*y*y;
	cout<<ans<<endl;


	return 0;
}