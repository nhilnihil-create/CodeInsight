#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 500;

int dp[N], n, m, vel[N];

int main(){
	scanf("%d%d", &n, &m);
	dp[1] = 1;
	for(int i = 1;i <= n;i++)
		vel[i] = 1;
	for(int i = 0;i < m;i++){
		int x, y; scanf("%d%d", &x, &y);
		if(dp[x]){
			dp[y] = 1;
		}
		vel[y]++; vel[x]--;
		if(!vel[x])
			dp[x] = 0;
	}
	int sol = 0;
	for(int i = 1;i <= n;i++)
		sol += dp[i];
	printf("%d\n", sol);
}