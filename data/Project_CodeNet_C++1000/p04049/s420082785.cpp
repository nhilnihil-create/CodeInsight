#include <bits/stdc++.h>
#define INF 9999

using namespace std;

int n, k, pre, ans;
vector<vector<int>> G(2002);
int d[2002];

void search(int p, int s, int sum){
	if(sum > k/2)pre++;
	d[s] = sum;
	for(int i = 0; i < (int)G[s].size(); i++)if(G[s][i] != p)search(s, G[s][i], sum+1);
}
void search2(int p, int s, int sum){
	if(min(d[s], sum) > k/2)pre++;
	for(int i = 0; i < (int)G[s].size(); i++)if(G[s][i] != p)search2(s, G[s][i], sum+1);
}


int main(){
	ans = INF;
	cin >> n >> k;
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if(k%2==0){
		for(int i = 0; i < n; i++){
			pre = 0;
			search(INF, i, 0);
			ans = min(ans, pre);
		}
	}
	else{
		for(int i = 0; i < n; i++){
			fill(d, d+n, 0);
			search(INF, i, 0);
			for(int j = 0; j < (int)G[i].size(); j++){
				if(i < G[i][j])continue;
				pre = 0;
				search2(INF, G[i][j], 0);
				ans = min(ans, pre);
			}
		}
	}
	cout << ans << endl;
    return 0;
}