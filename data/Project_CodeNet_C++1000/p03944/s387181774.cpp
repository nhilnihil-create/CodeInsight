#include <bits/stdc++.h>
using namespace std;

bool a[105][105];

int main(){
#ifdef _DEBUG
	freopen("in" , "r", stdin );
	freopen("out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	int w, h, n; cin >> w >> h >> n;
	for(int i = 0; i < n; i++){
		int x, y, t; cin >> x >> y >> t;
		if(t == 1){
			for(int i = 1; i <= x; i++)
			for(int j = 1; j <= h; j++) a[i][j] = 1;
		}
		if(t == 2){
			for(int i = x + 1; i <= w; i++)
			for(int j = 1; j <= h; j++) a[i][j] = 1;
		}
		if(t == 3){
			for(int i = 1; i <= w; i++)
			for(int j = 1; j <= y; j++) a[i][j] = 1;
		}
		if(t == 4){
			for(int i = 1; i <= w; i++)
			for(int j = y + 1; j <= h; j++) a[i][j] = 1;
		}
	}
	int ans = 0;
	for(int i = 1; i <= w; i++)
	for(int j = 1; j <= h; j++)
		if(!a[i][j]) ans++;
	cout << ans << '\n';
}
