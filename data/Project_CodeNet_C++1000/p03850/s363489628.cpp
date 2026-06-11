#include<cstring>
#include<iostream>
#include<cstdio>
#define int long long
#define maxn 100005
using namespace std;
typedef long long ll;
pair<int, char> a[maxn];
ll st[maxn];
ll p[maxn];
ll c[maxn], b[maxn];
signed main() {
	int n;
	cin >> n;
	char s[2];
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i].first);
		if(i < n) {
			scanf("%s",s);
			a[i].second = s[0];
		}
	}
	a[0] = make_pair(0,'&');
	int z=0;
	for(int i=1; i<=n; i++) {
		char op = a[i-1].second;
		if(op == '-') {
			a[i].first *= -1;
			st[++z] = a[i].first;
		}
		int pre = a[i-1].first;
		if(pre <= 0 && a[i].first > 0) {
			st[++z] = a[i].first;
		}
		if(pre > 0 && a[i].first > 0) {
			st[z] += a[i].first;
		}
	}
	c[z] = abs(st[z]);
	for(int i=z-1; i>=1; i--) c[i] = c[i+1] + abs(st[i]);
	for(int i=1; i<=z; i++) p[i] = p[i-1] + st[i];
	ll ans = p[z];
	for(int i=1; i<z; i++) {
		if(st[i+1] < 0) ans = max(ans,p[i+1]-st[i+2]+c[i+3]);
	}
	cout << ans << endl;
}