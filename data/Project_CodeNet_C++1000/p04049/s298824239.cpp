#include <bits/stdc++.h>
using namespace std;
#define oo 1000000
#define mod 1000000007
const int N = 2010;
int n , u , v , k;
vector< int > g[N];
int cur;

int a =0 , b = 0;

void DFS(int node,int prnt,int d){
	if(d == cur){
		b++;
		return;
	}
	a++;
	for(int i = 0 ;i < (int)g[node].size();i++){
		if(g[node][i] == prnt) continue;
		DFS(g[node][i] , node , d + 1);
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 0 ;i < n - 1;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 0;
	cur = k / 2 + 1;
	int sum = 0 , mx = 0;
	for(int i = 1;i <= n;i++){
		sum = mx = 0;
		for(int j = 0 ;j < (int)g[i].size();j++){
			a = b = 0;
			DFS(g[i][j] , i , 1);
			sum += a;
			mx = max(mx,b);
		}
		if(k & 1)
			ans = max(ans , sum + mx + 1);
		else
			ans = max(ans , sum + 1);
	}
	cout << n - ans << endl;
	return 0;
}