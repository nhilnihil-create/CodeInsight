#include <bits/stdc++.h>
#define sz(c)      int(c.size())
#define rep(i,a,b) for (int i=a; i<(b); ++i)
#define per(i,a,b) for (int i=(b)-1; i>=(a); --i)
using namespace std;
using ll = long long;



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);

	int H,W,h,w;
	cin>>H>>W>>h>>w;
	if (H%h==0 && W%w==0) {
		cout<<"No\n"<<endl;
		return 0;
	}
	
	cout<<"Yes\n";
	
	const int T=501;
	rep(i,0,H) rep(j,0,W) {
		if (H%h!=0) {
			if (i%h==0) {
				cout<<T*(h-1)-1;
			} else {
				cout<<-T;
			}
		} else {
			if (j%w==0) {
				cout<<T*(w-1)-1;
			} else {
				cout<<-T;
			}
		}
		cout<<" \n"[j+1==W];
	}
}
