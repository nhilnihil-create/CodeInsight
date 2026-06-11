#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	int lx,ly,rx,ry;
	int w,h,n;
	cin >> w >> h >> n;
	lx=0; ly=0;
	rx = w; ry = h;
	rep(i,n){
		int a,b,c;
		cin >> a >> b >> c;
		if(c==1) lx = max(lx,a);
		if(c==2) rx = min(rx,a);
		if(c==3) ly = max(ly,b);
		if(c==4) ry = min(ry,b);
	}
	if((rx-lx)<=0||(ry-ly)<=0){
		cout << 0 << endl;
		return 0;
	}
	cout << max(0,(rx-lx)*(ry-ly)) << endl;
	return 0;
}
