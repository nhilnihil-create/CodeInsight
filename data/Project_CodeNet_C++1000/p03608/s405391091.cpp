#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 0x3f3f3f3f;
int N, M, R;
int r[10];
int A[50000],B[50000],C[50000];
int dist[250][250];

void solve()
{
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=N;++i)dist[i][i]=0;
	for(int i=0;i<M;++i){
		dist[A[i]][B[i]]=dist[B[i]][A[i]]=C[i];
	}
	for(int k=1;k<=N;++k)for(int i=1;i<=N;++i)for(int j=1;j<=N;++j){
		dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	}
	int ans = INF;
	sort(r,r+R);
	do{
		int cur=0;
		bool ok = true;
		for(int i=1;i<R;++i){
			if(dist[r[i]][r[i-1]]==INF){
				ok = false;
				break;
			}
			cur += dist[r[i]][r[i-1]];
		}
		if(ok) ans = min(ans, cur);
	}while(next_permutation(r,r+R));
	cout << ans << '\n';
}

int main()
{
	cin >> N >> M >> R;
	for(int i=0;i<R;++i) cin >> r[i];
	for(int i=0;i<M;++i) cin >> A[i] >> B[i] >> C[i];
	solve();
	return 0;
}