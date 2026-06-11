#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> P;

const int N = 2005;

vector <int> tr[N];
vector <int> rec1;
vector <int> rec2;
int used[N];
int k;
queue <P> q;

void bfs(int x){
	int cnt1 = 0, cnt2 = 0, u, v, d;
	q.push({x, 1});
	used[x] = 1;
	while (!q.empty()){
		u = q.front().first; d = q.front().second; q.pop();
		if (d <= (k + 1) / 2) cnt1++;
		if (d <= (k + 1) / 2 - 1) cnt2++;
		for (int i = 0; i < tr[u].size(); i++){
			v = tr[u][i];
			if (!used[v]){
				q.push({v, d + 1});
				used[v] = 1;
			}
		}
	}
	rec1.push_back(cnt1);
	rec2.push_back(cnt2);
}

int main(){
	int n, u, v, ans, sum, maxx;
	scanf("%d %d",&n,&k);
	for (int i = 1; i <= n - 1; i++){
		scanf("%d %d",&u,&v);
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	ans = 0;
	for (int i = 1; i <= n; i++){
		rec1.clear();
		rec2.clear();
		memset(used, 0, sizeof(used));
		used[i] = 1;
		for (int j = 0; j < tr[i].size(); j++) bfs(tr[i][j]);
		if (k & 1){
			sum = 0; maxx = 0;
			for (int j = 0; j < tr[i].size(); j++){
				sum += rec2[j];
				maxx = max(maxx, rec1[j] - rec2[j]);
			}
			ans = max(ans, sum + maxx);
		}
		else{
			sum = 0;
			for (int j = 0; j < tr[i].size(); j++) sum += rec1[j];
			ans = max(ans, sum);
		}
	}
	printf("%d\n", n - 1 - ans);
	return 0;
}