#include <bits/stdc++.h>
using namespace std;
const int maxn = 123456, lg = 20;
int a[maxn], p[lg][maxn];
int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	int L; cin >> L;
	int j = 0;
	for(int i = 0; i < n; i++){
		while(j + 1 < n && a[j + 1] - a[i] <= L) j++;
		p[0][i] = j;
	}
	for(int i = 1; i < lg; i++){
		for(int j = 0; j < n; j++){
			p[i][j] = p[i - 1][p[i - 1][j]];
		}
	}
	int q; cin >> q;
	while(q--){
		int l, r; cin >> l >> r;
		if(l > r) swap(l, r);
		l--; r--;
		int ans = 0;
		for(int i = lg - 1; i >= 0; i--) if(p[i][l] < r) l = p[i][l], ans |= 1<<i;
		ans++;
		cout << ans << endl;
	}
	return 0;
}
