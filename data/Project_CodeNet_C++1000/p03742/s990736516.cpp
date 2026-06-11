#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

bool dfs(int X, int Y) {
	bool res = false;
	for(int k = 0; k < 2; ++k) {
		for(int i = 2; i <= X; i += 2) {
			res = res || !dfs(X - i, Y + i / 2);
		}
		swap(X, Y);
	}
	return res;
}

signed main(){
	int X, Y;
	cin >> X >> Y;
	if(abs(X - Y) < 2) {
		cout << "Brown" << endl;
	} else {
		cout << "Alice" << endl;
	}
	return 0;
}
