#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<bool> color(8);
	rep(i,8) color[i]=false;
	rep(i,n) cin >> a[i];
	int cnt=0;
	rep(i,n){
		int b = a[i];
		if(b>=1&&b<=399) color[0]=true;
		if(b>=400&&b<=799) color[1]=true;
		if(b>=800&&b<=1199) color[2]=true;
		if(b>=1200&&b<=1599) color[3]=true;
		if(b>=1600&&b<=1999) color[4]=true;
		if(b>=2000&&b<=2399) color[5]=true;
		if(b>=2400&&b<=2799) color[6]=true;
		if(b>=2800&&b<=3199) color[7]=true;
		if(b>=3200) cnt++;
	}
	int ans=0;
	rep(i,8){
		if(color[i]==1) ans++;
	}
	int ans2;
	ans2 = ans+cnt;
	if(ans==0){
		ans=1;
	}
	cout << ans << ' ' << ans2 << endl;
	return 0;
}
