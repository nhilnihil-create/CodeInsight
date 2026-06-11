#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll dist[305][305],edit[305][305];
int main(){
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			scanf("%lld", &dist[i][j]);
			edit[i][j] = dist[i][j];
		}
	}
	for (int k = 1; k <= N; k++){
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				if (dist[i][j] > dist[i][k] + dist[k][j])
					return !printf("-1");
				if (k!=i && k!=j && dist[i][j] == dist[i][k] + dist[k][j])
					edit[i][j] = 0;
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
			ans += edit[i][j];
	printf("%lld", ans);
}