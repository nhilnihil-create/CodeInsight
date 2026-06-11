#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	int W, H, N;
	cin >> W >> H >> N;
	int xl=0, xr=W, yd=0, yu=H;
	rep(i,N){
		int x, y, a;
		cin >> x >> y >> a;
		if(a==1) xl=max(xl,x);
		if(a==2) xr=min(xr,x);
		if(a==3) yd=max(yd,y);
		if(a==4) yu=min(yu,y);
	}
	int X=max(0,xr-xl), Y=max(0,yu-yd);
	cout << X*Y << endl;

	return 0;
}