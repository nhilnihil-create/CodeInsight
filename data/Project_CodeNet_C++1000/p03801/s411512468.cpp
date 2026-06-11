#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
const int mod = 1e9 + 7;

int n;
pi a[MAXN];
lint ret[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort(a, a + n, [&](const pi &a, const pi &b){
		return pi(-a.first, a.second) < pi(-b.first, b.second);
	});
	int run_min = 1e9;
	for(int i=0; i<n; ){
		int e = i;
		while(e < n && a[i].first == a[e].first) e++;
		for(int j=i; j<e; j++) run_min = min(run_min, a[j].second);
		ret[run_min] += 1ll * (a[i].first - a[e].first) * e;
		i = e;
	}
	for(int i=0; i<n; i++) printf("%lld\n", ret[i]);
}
