#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll x,y;
	cin >> x >> y;

	ll ans = 0;
	if(x>=0 && y>=0){
		if(x<=y) ans = abs(y-x);
		else { ans = abs(x-y)+2; if(y==0)ans--;}
	} else if(x<0 && y<0){
		if(x<y) ans = abs(y-x);
		else ans = abs(x-y)+2;
	} else {
		if(x<y) ans = min(abs(y-x),abs(-x-y)+1);
		else ans = abs(-x-y)+1;
	}
	cout << ans << endl;
	return 0;
}

