#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000

struct data{
	int v,d,c;
};

int main(){
	int N,M;
	cin>>N>>M;
	
	vector<vector<int>> E(N,vector<int>(0));
	
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	int Q;
	cin>>Q;
	
	vector<data> query(Q);
	for(int i=0;i<Q;i++){
		data D;
		scanf("%d %d %d",&D.v,&D.d,&D.c);
		D.v--;
		query[i] = D;
	}
	
	reverse(query.begin(),query.end());
	
	vector<vector<bool>> painted_flag(N,vector<bool>(11,false));
	
	vector<int> ans(N,0);
	
	for(int i=0;i<Q;i++){
		queue<int> q;
		q.push(query[i].v);
		int x = q.size();
		for(int j=0;j<=query[i].d;j++){
			int a = 0;
			while(a!=x){
				a++;
				int V = q.front();
				q.pop();
				if(painted_flag[V][query[i].d-j])continue;
				for(int k=query[i].d-j;k>=0;k--){
					painted_flag[V][k]=true;
				}
				if(ans[V]==0)ans[V]=query[i].c;
				for(int k=0;k<E[V].size();k++){
					q.push(E[V][k]);
				}
			}
			x=q.size();
		}
		
		
	}
	
	for(int i=0;i<N;i++){
		printf("%d\n",ans[i]);
	}
	
	
	return 0;
}