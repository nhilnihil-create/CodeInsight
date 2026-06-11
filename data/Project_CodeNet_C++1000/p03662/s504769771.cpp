/* long long or int & the MAX_INT or MIN_INT */
/* the size of a[] & inline */
/* xx 396 */

#include<bits/stdc++.h>
using namespace std;

const int MAX_N=1e5+10;

int cnt[MAX_N],N;
vector <int> G[MAX_N];
int First;
vector <int> Main;

inline void dfs(int at,int p){
	cnt[at]=1; Main.push_back(at);
	if(at==N-1) First=Main[(Main.size()+1)/2];
	for(int i=0;i<G[at].size();i++){
		int to=G[at][i];
		if(to!=p){
			dfs(to,at);
			cnt[at]+=cnt[to];
		}
	}
	Main.resize(Main.size()-1);
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>N;
	for(int i=0;i<N-1;i++){
		int a,b; cin>>a>>b; a--; b--;
		G[a].push_back(b); G[b].push_back(a);
	}
	dfs(0,-1);
	bool win=cnt[First]*2<N;
	if(win) cout<<"Fennec"<<endl;
	else cout<<"Snuke"<<endl;
	return 0;
}