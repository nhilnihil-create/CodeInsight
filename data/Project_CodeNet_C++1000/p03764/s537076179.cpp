#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int main(){
	int N,M; cin >> N >> M;
	vector<LL> x(N),y(M);
	repp(i,0,N) cin >> x[i];
	repp(i,0,M) cin >> y[i];
	LL sx = 0, sy = 0;
	const LL mod = 1e9+7;
	repp(i,1,N) (sx += (x[i]-x[i-1])*i%mod*(N-i)) %= mod;
	repp(i,1,M) (sy += (y[i]-y[i-1])*i%mod*(M-i)) %= mod;
	cout << sx*sy%mod << endl;
	return 0;
}
