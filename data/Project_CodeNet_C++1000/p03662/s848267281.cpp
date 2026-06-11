#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll mod = 1000000007;


int ri() {
    int n;
    scanf("%d", &n);
    return n;
}

int n;
vector<vector<int>> hen;
vector<int> f, s; 

void bfs(int t, vector<int>& v){
	queue<int> que;
	vector<bool> seen(n);
	seen[t] = 1;
	que.push(t);
	while(que.size()){
		auto cur = que.front(); que.pop();
		for(auto i : hen[cur]){
			if(seen[i])continue;
			v[i] = v[cur] + 1;
			seen[i] = 1;
			que.push(i);
		}
	}
}

int main()
{
	n = ri();
	hen.resize(n);
	f.resize(n);
	s.resize(n);
	for(int i = 0; i < n - 1; i++){
		int a = ri(), b = ri(); a--; b--;
		hen[a].push_back(b);
		hen[b].push_back(a);
	}
	bfs(0, f);
	bfs(n - 1, s);
	int cnt = 0; //fennecが塗れる
	for(int i = 0; i < n; i++){
		//cerr << f[i] << " : " << s[i] << endl;
		if(f[i] <= s[i])cnt++;
	}
	//cerr << cnt << endl;

	cout << (cnt > n - cnt ? "Fennec" : "Snuke") << endl;
}