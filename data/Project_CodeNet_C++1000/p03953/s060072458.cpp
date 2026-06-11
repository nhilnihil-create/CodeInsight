#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool vis[100050];
ll w[100050], nxt[100050], que[100050], output[100050];

int main(){
	int n, m;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &w[i]), nxt[i] = i;
	for(int i = n; i >= 1; i--) w[i] -= w[i-1];
	ll k;
	ll a;
	scanf("%d %lld", &m, &k);
	for(int i = 1; i <= m; i++) scanf("%lld", &a), swap(nxt[a], nxt[a+1]);
	for(int i = 1; i <= n; i++){
		if(!vis[i]) {
			int now = i, cnt = 0;
			while(!vis[now]){
				vis[now] = 1;
				que[++cnt] = now;
				now = nxt[now];
			}
			for(int j = 1; j <= cnt; j++){
				ll t = (0ll+j+k-2)%cnt+1;
				output[que[j]] = w[nxt[que[t]]];
			}
		}
	}
	ll p = 0;
	for(int i = 1; i <= n; i++) p += output[i], printf("%lld\n", p);
}