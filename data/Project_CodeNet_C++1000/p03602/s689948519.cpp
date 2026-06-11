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
		int val = inf;
		for(int i = 1 ; i <= n ; ++i){
			if(i == a || i == b){
				continue;
			}
			val = min(val , graph[a][i] + graph[i][b]);
		}
		if(val < c){
			printf("-1\n");
			return 0;
		}
		if(val == c){
			continue;
		}
		ans += c;
	}
	printf("%lld\n" , ans);
}