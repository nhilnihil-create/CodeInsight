#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define db double
#define ll long long
#define inf 0x3f3f3f3f
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

const int maxn = 200005;
int n, m;
ll k, ans;
ll a[maxn];
ll t[maxn];
ll b[maxn];
ll ask(int x){
	ll ret = 0;
	for(;x;x-=x&-x)	ret += b[x];
	return ret;
}
void change(int x){
	while (x <= m + 1){
		++b[x];
		x += (x & -x);
	}
}
int main(){
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; ++i){
		scanf("%lld", &a[i]);
		t[i] = (a[i] += a[i-1] - k);
	}
	sort(t, t + n + 1);
	m = unique(t, t + n + 1) - t + 1;
	for (int i = 0; i <= n; ++i){
		a[i] = lower_bound(t, t + m, a[i]) - t + 1;
		ans += ask(a[i]);
		change(a[i]);
	}
	printf("%lld", ans);
	return 0;
}
