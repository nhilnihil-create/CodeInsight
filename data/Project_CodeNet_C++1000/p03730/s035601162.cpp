#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	bool ok = false;
	rep(i,100){
		int wa = 0;
		wa += 1*i*a;
		if(wa%b == c) {
			ok = true;
			break;
		}
	}
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}