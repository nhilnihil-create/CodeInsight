#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	char a[H][W];
	rep(i,H)rep(j,W) cin >> a[i][j];

	rep(i,W+2) cout << '#';
	cout << "\n";
	rep(i,H){
		cout << '#';
		rep(j,W) cout << a[i][j];
		cout << "#\n";
	}
	rep(i,W+2) cout << '#';
	cout << "\n";

	return 0;
}
