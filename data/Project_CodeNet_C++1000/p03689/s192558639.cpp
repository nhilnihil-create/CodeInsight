#include <bits/stdc++.h>
#define sz(c)      int(c.size())
#define rep(i,a,b) for (int i=a; i<(b); ++i)
#define per(i,a,b) for (int i=(b)-1; i>=(a); --i)
using namespace std;
using ll = long long;

int H,W,h,w;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);
	
	cin>>H>>W>>h>>w;
	
	if (H%h==0 && W%w==0) {
		cout<<"No\n";
		return 0;
	}

	cout<<"Yes\n";
	rep(i,0,H) rep(j,0,W) {
		if ((i+1)%h==0 && (j+1)%w==0) cout<<-4000*(h*w-1)-1; else cout<<4000;
		cout<<" \n"[j+1==W];
	}
}
