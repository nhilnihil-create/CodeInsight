/* long long or int & the MAX_INT or MIN_INT */
/* the size of a[] & inline */
/* xx 396 */

#include<bits/stdc++.h>
using namespace std;

const int MAX_N=1e5+10;

vector <int> G[MAX_N],Main,now;
int col[MAX_N],N;

inline void dfs(int at,int p){
	now.push_back(at);
	if(at==N-1) Main=now;
	for(int i=0;i<G[at].size();i++){
		int to=G[at][i];
		if(to!=p) dfs(to,at);
	}
	now.resize(now.size()-1);
}

inline void color(int at,int p){
	int c=col[at];
	for(int i=0;i<G[at].size();i++){
		int to=G[at][i];
		if(col[to]==-1) col[to]=c;
		if(to!=p) color(to,at);
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for(int i=0;i<MAX_N;i++) col[i]=-1;
	cin>>N;
	for(int i=0;i<N-1;i++){
		int a,b; cin>>a>>b; a--; b--;
		G[a].push_back(b); G[b].push_back(a);
	}	
	dfs(0,-1);
	for(int i=0;i<(Main.size()+1)/2;i++) col[Main[i]]=1;
	for(int i=(Main.size()+1)/2;i<Main.size();i++) col[Main[i]]=0;
	color(0,-1);
	int sum1=0,sum2=0;
	for(int i=0;i<N;i++) if(col[i]==1) sum1++;
	for(int i=0;i<N;i++) if(col[i]==0) sum2++;
	if(sum1>sum2) cout<<"Fennec"<<endl;
	else cout<<"Snuke"<<endl;
	return 0;
}