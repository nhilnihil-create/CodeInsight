#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	ll x,y;
	cin >> x >> y;
	ll dis = abs(y)-abs(x);
	ll ans;
	if(y>=x){
		if(y>=0&&x>=0||x<0&&y<0)
			ans = y-x;
		else{
			if(abs(y)>abs(x))
				ans = min(1+y-abs(x),y-x);
			else
				ans = min(y-x,abs(x)-abs(y)+1);
		}
	}
	else{
		if(x<=0&&y<=0){
			ans = min(2+abs(y)-abs(x),abs(y)-x+1);
		}
		if(x>0&&y<0){
			if(abs(x)<=abs(y))
				ans = abs(y)-x+1;
			else
				ans = x-abs(y)+1;
		}
		if(x>=0&&y>=0)
			ans = min(1+y+x,1+x-y+1);

	}
	cout << ans << endl;
	return 0;
}
