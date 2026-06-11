#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<vector<int>> v(100010);
ll N;
int M,a,b;
int color[100010] = {0};

bool dfs(int n,int c){
	color[n] = c;
	bool j = true;
	for(int i=0;i<v[n].size();i++){
		if(color[v[n][i]] == c) j = false;
		else if(color[v[n][i]] == 0 && !dfs(v[n][i],-c)) j = false;
	}
	return j;
}

int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	ll nibu = 0,notnibu = 0,koritsu = 0;
	for(int i=1;i<=N;i++){
		if(color[i]==0){
			if(v[i].size()==0) koritsu++;
			else if(dfs(i,1)) nibu++;
			else notnibu++;
		}
	}
	cout << 2*koritsu*N-koritsu*koritsu + notnibu*notnibu + 2*notnibu*nibu + 2*nibu*nibu << endl;
}