#include <bits/stdc++.h>

using namespace std;

int n, t;
int a[111111];
int mn[111111], mx[111111];
map<int, int> mp;

int main(){
//	freopen("input.inp", "r", stdin);
	scanf("%d%d",&n,&t);
	for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
	mn[1] = a[1];
	mx[n] = a[n];
	for(int i = 2; i <= n; ++i) mn[i] = min(mn[i - 1], a[i]);
	for(int i = n - 1; i >= 1; --i) mx[i] = max(mx[i + 1], a[i]);
	int cur = 0;
	for(int i = 1; i < n; ++i){
		cur = max(cur, mx[i + 1] - mn[i]);
	}
	for(int i = 1; i <= n; ++i){
		if (!mp[a[i]]) mp[a[i]] = i;
	}
	int an = 0;
	for(int i = 1; i <= n; ++i){
		if (mp[a[i] + cur] && mp[a[i] + cur] > mp[a[i]]) ++an;
	}
	printf("%d",an);
	return 0;
}