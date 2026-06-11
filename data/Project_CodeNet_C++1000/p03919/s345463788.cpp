#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	int h,w;
	cin >> h >> w;

	string in;
	for(int i = 1; i <= h; i++){
		for(int j = 0; j < w; j++){
			cin >> in;
			if(in == "snuke")
				cout << (char)('A'+j) << i << endl;
		}
	}

	return 0;
}