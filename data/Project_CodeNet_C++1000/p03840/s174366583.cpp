#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int main(){
	LL I,O,T,J,L,S,Z; cin >> I >> O >> T >> J >> L >> S >> Z;
	LL ans = I/2*2 + O + J/2*2 + L/2*2;
	if(I && J && L) ans = max(ans,3+O+(I-1)/2*2+(J-1)/2*2+(L-1)/2*2);
	cout << ans << endl;
	return 0;
}
