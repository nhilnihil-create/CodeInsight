/* long long or int & the MAX_INT or MIN_INT */
/* the size of a[] & inline */
/* xx 396 */

#include<bits/stdc++.h>
using namespace std;

const int MAX_N=1e5+10;

int dist[MAX_N][2],N;
vector <int> G[MAX_N];

inline void dfs(int Mark,int at,int fr){
	for(int i=0;i<G[at].size();i++){
		int to=G[at][i];
		if(to!=fr){
			dist[to][Mark]=dist[at][Mark]+1;
			dfs(Mark,to,at);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>N;
	for(int i=0;i<N-1;i++){
		int a,b; cin>>a>>b; a--; b--;
		G[a].push_back(b); G[b].push_back(a);
	}
	dist[0][0]=0; dist[N-1][1]=0;
	dfs(0,0,-1); dfs(1,N-1,-1);
	int sumS=0,sumF=0;
	for(int i=0;i<N;i++){
		if(dist[i][0]>dist[i][1]) sumS++;
		else sumF++;
	}
	if(sumF>sumS) cout<<"Fennec"<<endl;
	else cout<<"Snuke"<<endl;
	return 0;  
}