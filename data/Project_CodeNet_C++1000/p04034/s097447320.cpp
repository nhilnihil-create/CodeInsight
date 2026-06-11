#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef long long LL;

int n, m, num[N], ans;
bool vis[N];

int main() {
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		num[i] = 1;
	vis[1] = 1;
	for(int i = 1, x, y; i <= m; i++) {
		cin>>x>>y;
		num[x]--, num[y]++;
		vis[y] |= vis[x];
		if(!num[x]) vis[x] = 0;
	}
	for(int i = 1; i <= n; i++)
		ans += vis[i];
	cout<<ans<<endl;
	return 0;
}