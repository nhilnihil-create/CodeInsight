#include <bits/stdc++.h>

using namespace std;

long long inf = (1LL << 62LL);

int N;
long long tree[8005];

void update(int i, long long v){
	for(i += N;i > 0;i >>= 1) tree[i] = min(tree[i], v);
}

long long query(int l, int r){
	long long res = inf;
	for(l += N, r += N;l < r;l >>= 1, r>>= 1){
		if(l&1) res = min(res, tree[l++]);
		if(r&1) res = min(res, tree[--r]);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	long long n, x; cin >> n >> x;
	N = 2 * n;
	
	fill(tree,tree+8005, inf);
	
	for(int i = 0;i < n;i++){
		long long a; cin >> a;
		update(i, a);
		update(i + n, a);
	}
	
	long long ans = inf;
	for(long long take = 0;take < n;take++){
		long long res = take * x;
		for(int i = 0;i < n;i++){
			long long r = i + n;
			long long l = r - take;
			res += query(l,r+1);
		}
		//cout << res << "\n";
		ans = min(res, ans);
	}
	
	cout << ans;
}
