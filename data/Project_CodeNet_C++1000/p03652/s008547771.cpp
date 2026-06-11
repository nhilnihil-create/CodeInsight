#include<bits/stdc++.h>
#define Rint register int
using namespace std;
const int N = 303;
int T, n, m, a[N][N], cnt[N], q[N], front, rear, np[N];
bool vis[N];
inline bool check(int x){
	front = rear = 0;
	for(Rint i = 1;i <= m;i ++) cnt[i] = vis[i] = 0;
	for(Rint i = 1;i <= n;i ++) ++ cnt[a[i][np[i] = 1]];
	for(Rint i = 1;i <= m;i ++) if(cnt[i] > x) vis[q[rear ++] = i] = true;
	while(front < rear){
		int now = q[front ++];
		for(Rint i = 1;i <= n;i ++)
			while(np[i] <= m && vis[a[i][np[i]]]) ++ np[i];
		for(Rint i = 1;i <= m;i ++) cnt[i] = 0;
		for(Rint i = 1;i <= n;i ++) ++ cnt[a[i][np[i]]];
		for(Rint i = 1;i <= m;i ++) if(cnt[i] > x && !vis[i]) vis[q[rear ++] = i] = true;
	}
	for(Rint i = 1;i <= m;i ++) if(!vis[i]) return true;
	return false;
}
int main(){

		scanf("%d%d", &n, &m);
		for(Rint i = 1;i <= n;i ++)
			for(Rint j = 1;j <= m;j ++)
				scanf("%d", a[i] + j);
		int l = 1, r = n, mid, ans = 0;
		while(l <= r){
			mid = l + r >> 1;
			if(check(mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);

}