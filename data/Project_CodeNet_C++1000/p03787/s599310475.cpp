#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

struct renketu{
	int n,is_nibu;
};

int main(){
	int N,M;
	cin>>N>>M;
	
	vector<vector<int>> E(N,vector<int>(0));
	
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	vector<int> dis(N,-1);
	vector<renketu> V;
	int ko=0,nibu=0,normal=0;
	for(int i=0;i<N;i++){
		if(dis[i]!=-1)continue;
		int cnt = 1;
		dis[i] = 0;
		queue<int> q;
		q.push(i);
		int f = 1;
		while(q.size()!=0){
			int from = q.front();
			q.pop();
			for(int j=0;j<E[from].size();j++){
				int to = E[from][j];
				if(dis[to]!=-1){
					if(dis[to]%2==dis[from]%2){
						f=0;
					}
				}
				else{
					dis[to] = dis[from]+1;
					q.push(to);
					cnt++;
				}
			}
		}
		renketu R;
		R.n=cnt;
		R.is_nibu=f;
		V.push_back(R);
		
		if(R.n==1){
			ko++;
		}
		else{
			if(f)nibu++;
			else normal++;
		}
		
	}
	long long ans = 0;
	
	for(int i=0;i<V.size();i++){
		if(V[i].n==1){
			ans += (long long)N;
		}
		else{
			if(V[i].is_nibu){
				ans += (long long)V[i].n*ko;
				ans += (long long)2*nibu;
				ans += (long long)normal;
			}
			else{
				ans += (long long)V[i].n*ko;
				ans += (long long)nibu+normal;
			}
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
