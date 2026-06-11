#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	int cnt = 0;
	int itr = 0;
	vector<vector<int>> ans(h,vector<int>(w));
	for(int y=0;y<h;y++) {
		if(y%2 == 0) {
			for(int x=0;x<w;x++) {
				if(cnt == a[itr]) {
					cnt = 0;
					itr++;	
				}
				ans[y][x] = itr+1;
				cnt++;
			}
		} else {
			for(int x=w-1;x>=0;x--) {
				if(cnt == a[itr]) {
					cnt = 0;
					itr++;	
				}
				ans[y][x] = itr+1;
				cnt++;
			}
		}
	}
	for(int y=0;y<h;y++)
		for(int x=0;x<w;x++)
			cout << ans[y][x] << ((x==w-1)?"\n":" ");
}