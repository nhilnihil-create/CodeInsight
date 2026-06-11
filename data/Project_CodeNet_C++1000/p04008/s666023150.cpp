#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n' 

int n,k;
int it[100001];
vector<int> adj[100001];
int co=0;
int ss[100001];
int endd[100001];
vector<pair<int,int>> ss3;
int par[100001];
set<int> cur2;
int ss2[100001];
int vis[100001];
void dfs(int no,int parr=-1,int levv=0){
	ss[no]=co;
	ss2[co]=no;
	par[no]=parr;
	co++;
	//cout<<no<<":"<<endl;
	ss3.pb({levv,no});
	for(auto j:adj[no]){
		if(j!=parr){
			dfs(j,no,levv+1);
		}
	}
	endd[no]=co-1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>it[i];
		it[i]--;
		if(i==0){
			if(it[i]!=0){
				ans+=1;
				it[i]=0;
			}
		}
		else{
			adj[it[i]].pb(i);
		}
	}
	dfs(0);
	sort(ss3.begin(),ss3.end());
	for(int i=0;i<n;i++){
		cur2.insert(i);
	}
	reverse(ss3.begin(),ss3.end());
	for(auto j:ss3){
		if(j.a<=k){
			continue;
		}
		if(vis[j.b]){
			continue;
		}
		int cur=j.b;
		for(int i=0;i<k-1;i++){
			cur=par[cur];
		}
		/*for(int i=ss[cur];i<=endd[cur];i++){
			assert(vis[ss2[i]]==0);
			vis[ss2[i]]=1;
		}*/
		auto jj=cur2.lower_bound(ss[cur]);
		vector<int> kk;
		while(true){
			if(jj==cur2.end()){
				break;
			}
			if(*jj>endd[cur]){
				break;
			}
			vis[ss2[*jj]]=1;
			kk.pb(*jj);
			jj++;
		}

		for(auto i:kk){
			cur2.erase(i);
		}
		ans+=1;
	///	cout<<j.a<<":"<<j.b<<":"<<cur<<endl;
	}
	cout<<ans;






	return 0;
}