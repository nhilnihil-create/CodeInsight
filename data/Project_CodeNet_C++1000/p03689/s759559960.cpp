#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H,W,h,w;
	cin >> H >> W >> h >> w;

	if(H%h == 0 && W%w == 0) {
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;
	rep(i,H){
		rep(j,W){
			int l;
			if((i%h == h-1) && (j%w == w-1)) l = -1000 * h*w + 1000 - 1;
			else l = 1000;

			cout << l << (j == W-1 ? "\r\n" : " ");
		}
	}
}