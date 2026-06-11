#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pi;
#define f first
#define s second

int N, K, a[200005], ans;
pi dis[200005];
int fw[200005];

void update(int x, int v) { //v is value, x is position
	if (x<=0) return;
    for (;x <=N+1; x+=x&(-x)) fw[x] += v; 
}
int sum(int x) {
	if (x<=0) return 0;
    int res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	
	int cursum = 0;
	for (int i = 1; i <= N; i++) {
		cursum += a[i];
		dis[i] = pi(cursum - (i*K), i);
		//~ printf("%d: %d running sum, %d v\n", i, cursum, cursum - (i*K));
		//~ if (a[i] >= K) ans++;
	}
	
	sort(dis+1, dis+N+2); //If 1-indexed, change sorting range as well
	pi cur = pi(-1, -1);
	for (int i = 1; i <= N+1; i++) {
		if (dis[i].f == cur.f && cur.s != -1) a[dis[i].s] = cur.s; //takes into account equal numbers
		else {
			cur = pi(dis[i].f, i);
			a[dis[i].s] = i;
		}
	}
	
	update(a[0], 1);
	
	for (int i = 1; i <= N; i++) {
		ans += sum(a[i]);
		//~ printf("From %d, %d added\n", i, sum(a[i]));
		update(a[i], 1);
		//~ printf("%d added 1\n", a[i]);
	}
	cout << ans;
}
