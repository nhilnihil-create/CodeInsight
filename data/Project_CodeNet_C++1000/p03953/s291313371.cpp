#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
ll X[MAXN],Y[MAXN];
int g[MAXN],fn[MAXN];
bool vis[MAXN];
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> X[i];
	for(int i=n;i;i--) {
		X[i] = X[i] - X[i-1];
		g[i] = i;
	}
	int m;
	ll K;
	cin >> m >> K;
	for(int i=1;i<=m;i++) {
		int pos;
		cin >> pos;
		swap(g[pos] , g[pos+1]);
	}
	
	for(int i=1;i<=n;i++)
		if(vis[i] == false) {
			static int st[MAXN];
			int cnt = 0;
			for(int j=i;vis[j] == false;j=g[j]) {
				st[cnt++] = j;
				vis[j] = true;
			}
			for(int j=0;j<cnt;j++)
				fn[st[j]] = st[(j+K)%cnt];
		}
	
	for(int i=1;i<=n;i++)
		Y[i] = X[fn[i]];
	for(int i=1;i<=n;i++) {
		Y[i] += Y[i-1];
		cout << Y[i] << ".0\n";
	}
}
