#include"bits/stdc++.h"
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair

int N, M;
vector<int> edge[100000];
bool flg[100000] = {};
deque<int> ans;
void dfs1(int now){
	flg[now] = true;
	for(int i=0; i<edge[now].size(); i++){
		if(flg[edge[now][i]]) continue;
		ans.push_back(edge[now][i]);
		dfs1(edge[now][i]);
		break;
	}
}
void dfs2(int now){
	flg[now] = true;
	for(int i=0; i<edge[now].size(); i++){
		if(flg[edge[now][i]]) continue;
		ans.push_front(edge[now][i]);
		dfs2(edge[now][i]);
		break;
	}
}

int main(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a >> b;
		edge[a-1].PB(b-1);
		edge[b-1].PB(a-1);
	}
	ans.push_back(0);
	dfs1(0);
	dfs2(0);
	cout << ans.size() << endl;
	while(!ans.empty()){
		cout << ans.front()+1;
		ans.pop_front();
		if(!ans.empty()) cout << " ";
	}
	cout << endl;
}