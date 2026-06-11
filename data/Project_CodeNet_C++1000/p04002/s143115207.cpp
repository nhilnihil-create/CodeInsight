#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> mp;
long long an[10];
int h, w, n;

bool ok(int a, int b){
	return a > 0 && b > 0 && a + 2 <= h && b + 2 <= w;
}

int main(){
//	freopen("input.inp", "r", stdin);
	scanf("%d%d%d",&h,&w,&n);
	for(int i = 1; i <= n; ++i){
		int x, y;
		scanf("%d%d",&x,&y);
		for(int j = x - 2; j <= x; ++j){
			for(int k = y - 2; k <= y; ++k){
				if (ok(j, k)) ++mp[make_pair(j, k)];
			}
		}
	}
	for(map<pair<int, int>, int>::iterator it = mp.begin(); it != mp.end(); ++it){
		++an[it->second];
	}
	for(int i = 1; i < 10; ++i) an[0] += an[i];
	an[0] = 1ll * (h - 2) * (w - 2) - an[0];
	for(int i = 0; i < 10; ++i) printf("%lld\n",an[i]);
	return 0;
}