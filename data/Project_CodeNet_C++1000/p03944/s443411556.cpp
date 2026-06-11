#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int W,H,N;
	cin >> W >> H >> N;

	int lx = 0, rx = W;
	int ly = 0, ry = H;

	while(N--){
		int x,y,t;
		cin >> x >> y >> t;

		if(t == 1) lx = max(lx,x);
		if(t == 2) rx = min(rx,x);
		if(t == 3) ly = max(ly,y);
		if(t == 4) ry = min(ry,y);

	}
	
	int ans = (rx - lx) * (ry - ly); 
	if(rx - lx < 0) ans = 0;
	if(ry - ly < 0) ans = 0;

	cout << ans << endl;

	return 0;
}

