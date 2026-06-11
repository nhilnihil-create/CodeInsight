#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, int> P;
static const int MAX_N = 200000;
static const int NIL = -1;

int N, K, L;
vector<int> Ga[MAX_N], Gb[MAX_N];
int numa[MAX_N], numb[MAX_N];

void dfs(int s, int c, vector<int> G[], int *num){
	if(num[s] == NIL) num[s] = c;
	for(int i = 0; i < G[s].size(); i++){
		if(num[G[s][i]] == NIL) dfs(G[s][i], c, G, num);
	}
	return ;
}

int main(){
	cin >> N >> K >> L;
	for(int i = 1; i <= K; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		Ga[a].push_back(b);
		Ga[b].push_back(a);
	}
	for(int i = 1; i <= L; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		Gb[a].push_back(b);
		Gb[b].push_back(a);
	}
	fill(numa, numa + N, NIL);
	fill(numb, numb + N, NIL);
	map<P, int> mpa;
	int cnta = 0, cntb = 0;
	for(int i = 0; i < N; i++){
		if(numa[i] == NIL){
			dfs(i, cnta, Ga, numa);
			cnta++;
		}
		if(numb[i] == NIL){
			dfs(i, cntb, Gb, numb);
			cntb++;
		}
		mpa[P(numa[i], numb[i])]++;
	}
	for(int i = 0; i < N; i++){
		cout << mpa[P(numa[i], numb[i])];
		if(i == N - 1) cout << endl;
		else cout << ' ';
	}
	return 0;
}