#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,k,mx = 0,a[100010],b[100010];
	long long ans = 0,ret = 0;
	bool f = false;
	cin >> n >> k;
	for (int i = 0;i < n;++i) scanf("%d %d", &a[i], &b[i]);
	for (int i = 31;i >= 0;--i) {
		if (k & 1 << i) {
			mx = i+1;
			break;
		}
	}
	
	for (int i = 0;i < n;++i) {
		f = true;
		for (int j = 0;j < 31;++j) {
			if (a[i] & (1 << j) && !(k & (1 << j))) {
				f = false;
				break;
			}
		}
		if (f) ret += b[i];
	}
	
	ans = ret;
	for (int i = 0;i < mx;++i) {
		if (k & 1 << i) {
			ret = 0;
			k ^= 1 << i;
			for (int j = 0;j < n;++j) {
				f = true;
				for (int l = 0;l < 31;++l) {
					if (a[j] & 1 << l && !(k & (1 << l))) {
						f = false;
						break;
					}
				}
				if (f) ret += b[j];
			}
			k |= 1 << i;
			ans = max(ans,ret);
		}
		else k |= 1 << i;
	}
		
	cout << ans << endl;
	return 0;
}