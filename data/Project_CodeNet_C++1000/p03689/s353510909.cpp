#include <bits/stdc++.h>
#define sz(c)      int(c.size())
#define rep(i,a,b) for (int i=a; i<(b); ++i)
#define per(i,a,b) for (int i=(b)-1; i>=(a); --i)
using namespace std;
using ll = long long;

const int MAXN=550;
int H,W,h,w;
int f[MAXN][MAXN];
mt19937 rng;

void add(int x,int y,int z) {
	for (int i=x; i<H; i|=i+1) {
		for (int j=y; j<W; j|=j+1) {
			f[i][j]+=z;
		}
	}
}

int sum(int x,int y) {
	int res=0;
	for (int i=x; i>=0; i&=i+1, i--) {
		for (int j=y; j>=0; j&=j+1, j--) {
			res+=f[i][j];
		}
	}
	return res;
}

int sum(int x1,int y1,int x2,int y2) {
	return sum(x2,y2) - sum(x2,y1-1) - sum(x1-1,y2) + sum(x1-1,y1-1);
}

bool find() {
	rep(i,h-1,H) rep(j,w-1,W) {
		int s=sum(i-h+1,j-w+1,i,j);
		if (s>=0) {
			add(i,j,-s-1);
		}
	}
	
	int s=sum(0,0,H-1,W-1);
	if (s>0) return true;
	return false;
}

int main() {
	rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);
	
	cin>>H>>W>>h>>w;
	rep(i,0,H) rep(j,0,W) add(i,j,4000);
	
	if (find()) {
		cout<<"Yes\n";
		rep(i,0,H) rep(j,0,W) cout<<sum(i,j,i,j)<<" \n"[j+1==W];
		return 0;
	}
	
	cout<<"No\n";
}
