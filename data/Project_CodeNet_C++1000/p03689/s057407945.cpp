#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

LL n,m,h,w;
LL val[505][505] = {0};

int main(){
	cin >> n >> m >> h >> w;
	if(!(n % h || m % w)){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for(LL i = h;i <= n;i += h)
		for(LL j = w;j <= m;j += w)
			val[i][j] = - (h * w * 1000 - 999);
	for(LL i = 1;i <= n;i ++)
		for(LL j = 1;j <= m;j ++)
			cout << (val[i][j] ? val[i][j] : 1000) << (j == m ? '\n' : ' ');
	return 0;
}//