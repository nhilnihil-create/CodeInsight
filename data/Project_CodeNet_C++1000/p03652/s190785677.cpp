#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
constexpr int MX = 305;
int n,m,a[MX][MX],ans = MX;
bool ex[MX];
int main(){
	scanf("%d%d", &n, &m);
	rep(i,n) rep(j,m) scanf("%d", a[i]+j);
	rep(i,m){
		int cnt[MX] = {}, v = 0;
		rep(i,n){
			rep(j,m) if(!ex[a[i][j]]){
				cnt[a[i][j]]++;
				break;
			}
		}
		for(int i=1; i<=m; i++) if(cnt[v] < cnt[i]) v = i;
		ex[v] = true;
		ans = min(ans, cnt[v]);
	}
	printf("%d\n", ans);
}