#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int h, w;

int main(void){
	cin >> h >> w;
	vector<string> c(h);
	rep(i, h) cin >> c[i];
	rep(i, 2*h){
		rep(j, w){
			cout << c[i/2][j];
		}
		cout << endl;
	}

	return 0;
}
