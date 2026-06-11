#include "bits/stdc++.h"
using namespace std;
const int N = 305;
const int inf = 1e9 + 9;
int n;
int graph[N][N];
vector < pair < int , pair < int , int > > > v;
unsigned dp[N][N];
long long ans;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			scanf("%d" , &graph[i][j]);
			if(j > i){
				v.push_back({graph[i][j] , {i , j}});
			}
			dp[i][j] = inf;
		}
		dp[i][i] = 0;
	}
	sort(v.begin() , v.end());
	for(auto it : v){
		int a = it.second.first;
		int b = it.second.second;
		int c = it.first;
		if(dp[a][b] < c){
			printf("-1\n");
			return 0;
		}
		if(dp[a][b] == c){
			continue;
		}
		ans += c;
		for(int i = 1 ; i <= n ; ++i){
			for(int j = 1 ; j <= n ; ++j){
				dp[i][j] = min(dp[i][j] , min(dp[i][a] + dp[b][j] , dp[i][b] + dp[a][j]) + c);
			}
		}
	}
	printf("%lld\n" , ans);
}