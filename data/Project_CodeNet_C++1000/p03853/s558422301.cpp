#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	char C[H+1][W+1];
	rep(i,H)rep(j,W) cin >> C[i+1][j+1];

	for (int i = 1; i <= 2*H; i++) {
		for (int j = 1; j <= W; j++) {
			cout << C[(i+1)/2][j];
			if (j == W) cout << "\n"; 
		}
	}
	return 0;
}
