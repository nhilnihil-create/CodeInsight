#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> dist;
const int INF=10000000000;
void warshall_floyd(int N){
	for(int i=0;i<N;i++)dist[i][i]=0;
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}


signed main(){
	int N,M,R; cin>>N>>M>>R;
	vector<int> town(R);
	for(int i=0;i<R;i++){cin>>town[i]; town[i]--;}
	dist.assign(N,vector<int>(N,INF));
	for(int i=0;i<M;i++){
		int A,B,C; cin>>A>>B>>C; A--; B--;
		dist[A][B]=C;
		dist[B][A]=C;
	}
	warshall_floyd(N);
	sort(town.begin(),town.end());
	int ans=10000000000;
	do{
		int start=town[0];
		int tmp_dist=0;
		for(int i=1;i<R;i++){
			tmp_dist+=dist[start][town[i]];
			start=town[i];
		}
		ans=min(tmp_dist,ans);

	}while(next_permutation(town.begin(),town.end()));

	cout<<ans<<endl;
}