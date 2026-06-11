#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N;
int a,b;
int D1[100010] = {0};
int DN[100010] = {0};
int V[100010] = {0};

void bfs1(vector<vector<int>>& v,int src){
	queue<int> Q;
	Q.push(src);
	D1[src] = 0;
	V[src] = 1;
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		for(int i=0;i<v[cur].size();i++){
			if(V[v[cur][i]]==0){
				D1[v[cur][i]] = D1[cur]+1;
				Q.push(v[cur][i]);
				V[v[cur][i]] = 1;
			}
		}
	}
	for(int i=1;i<=N;i++){
		V[i]=0;
	}
}

void bfsN(vector<vector<int>>& v,int src){
	queue<int> Q;
	Q.push(src);
	DN[src] = 0;
	V[src] = 1;
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		for(int i=0;i<v[cur].size();i++){
			if(V[v[cur][i]]==0){
				DN[v[cur][i]] = DN[cur]+1;
				Q.push(v[cur][i]);
				V[v[cur][i]] = 1;
			}
		}
	}
}


int main(){
	cin >> N;
	vector<vector<int>> v(N+1);
	for(int i=1;i<=N-1;i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs1(v,1);
	bfsN(v,N);
	int c1 = 0,cN = 0;
	for(int i=1;i<=N;i++){
		if(D1[i]<=DN[i]) c1++;
		else cN++;
	}
	//cout << c1 << " " << cN << endl;
	if(c1>cN) cout << "Fennec" << endl;
	else cout << "Snuke" << endl;
}