#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
char s[200200];
const int INF = 1e9;
const int A = 26;
vi p[A];
vvi g;
int mp[200200];
int n;
int dp[200200];
char res[200200];
int ds(int u) {
	if(u >= n) {return 1;}
	if(dp[u] != -1) {return dp[u];}
	int ma = INF;
	for(int i=0;i<A;i++) {
		ma = min(ma,1+ds(g[u][i]));
	}
	return dp[u] = ma;
}
int main() {
	scanf("%s ",s);
	n = strlen(s);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++) {
		int t = s[i]-'a';
		mp[i] = t;
		p[t].push_back(i);
	}
	for(int i=0;i<A;i++) {
		mp[i+n] = i;
		p[i].push_back(n+i);
	}
	g.assign(n+A,vi(A,-1));
	int pt[A];
	memset(pt,0,sizeof(pt));
	for(int i=0;i<n;i++) {
		pt[mp[i]]++;
		for(int j=0;j<A;j++) {
			g[i][j] = p[j][pt[j]];
		}
	}
	int sz = INF;
	int mi = -1;
	for(int i=0;i<A;i++) {
		if(ds(p[i][0]) < sz) {
			mi = i;
		}
		sz = min(sz,ds(p[i][0]));
	}
	res[0] = 'a'+mi;
	int st = p[mi][0];
	for(int i=1;i<sz;i++) {
		for(int j=0;j<A;j++) {
			int u = g[st][j];
			if(ds(u) == sz-i) {
				res[i] = 'a'+j;
				st = u;break;
			}
		}
	}
	res[sz] = '\0';
	printf("%s\n",res);
}
