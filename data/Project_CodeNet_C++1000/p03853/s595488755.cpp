#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);

	int H,W; cin>>H>>W;
	vector<vector<char>> C(H,vector<char>(W));
	rep(i,H)rep(j,W) cin>>C[i][j];

	for(int i=0; i<2*H; i++){
		for(int j=0; j<W; j++){
			cout << C[i/2][j];
		}
		cout << endl;
	}
}
