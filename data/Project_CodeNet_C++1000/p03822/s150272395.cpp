#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 300000
vector<int>e[N];

int dfs(int k){
	vector<int>b;
	int m = 0;
	if (e[k].size() == 0)return 0;
	f(i, e[k].size()){
		b.push_back(dfs(e[k][i]));
	}
	sort(b.begin(), b.end(),greater<int>());
	f(i, b.size()){
		m = max(m, b[i] + i + 1);
	}
	return m;
}


int main(){
	int n;
	int x, ans;
	scanf("%d", &n);
	for (int i = 1; i < n; i++){
		scanf("%d", &x);
		x--;
		e[x].push_back(i);
	}
	ans=dfs(0);
	printf("%d\n", ans);


	return 0;
}