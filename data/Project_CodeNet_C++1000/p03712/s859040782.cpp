#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int h, w;

int main(void){
	cin >> h >> w;
	vector<vector<char>> f(h+2, vector<char>(w+2, '#'));
	rep(i, h){
		rep(j, w){
			cin >> f[i+1][j+1];
		}
	}
	rep(i, h+2){
		rep(j, w+2){
			cout << f[i][j];
		}
		cout << endl;
	}
	return 0;
}
