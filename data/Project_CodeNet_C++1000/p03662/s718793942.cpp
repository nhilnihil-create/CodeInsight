#include <iostream>
#include <vector>
#define MAX_V 100010

using namespace std;
struct edge{int to,cost; };
vector<edge> G[MAX_V];

bool used[MAX_V];
int d[MAX_V],f[MAX_V];
int V,E;

void dfs(int s){
	used[s] = true;
	int i = 0;
	while(true){
		edge e = G[s][i];
		if(e.to==-1){
			break;
		}
		i++;
		if(!used[e.to]){
			d[e.to] = d[s]+e.cost;
			dfs(e.to);
		}
	}
}

int main(){
	int i,c=0;
	cin >> V;
	E = V-1;
	for(i=0;i<E;i++){
		int s,t;
		cin >> s >> t;
		s--; t--;
		edge e;
		e.to = t;
		e.cost = 1;
		G[s].push_back(e);
		e.to = s;
		e.cost = 1;
		G[t].push_back(e);
	}
	for(i=0;i<V;i++){
		edge e;
		e.to = -1; e.cost = 0;
		G[i].push_back(e);
		used[i] = false;
	}
	
	d[0] = 0;
	dfs(0);
	for(i=0;i<V;i++){
		f[i] = d[i];
		used[i] = false;
	}
	d[V-1] = 0;
	dfs(V-1);
	for(i=0;i<V;i++){
		if(f[i]<=d[i]){
			c++;
		}
	}
	if(c>V/2){
		cout << "Fennec" << endl;
	}else{
		cout << "Snuke" << endl;
	}
}
	


