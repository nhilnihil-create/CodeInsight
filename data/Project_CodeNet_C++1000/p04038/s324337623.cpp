#include <iostream>
using namespace std;
const int TT=1e9+7;
int n,k,F[2005][2005],fact[5005000];
inline int power(int base,int p,int ret=1) {
	for (;p;base=1ll*base*base%TT,p>>=1) if (p&1) ret=1ll*ret*base%TT; return ret;
}
inline int C(int x,int y) {
	return 1ll*fact[x]*power(1ll*fact[y]*fact[x-y]%TT,TT-2)%TT;
}
inline void M(int &x) {
	if (x>=TT) x-=TT;
}
int main() {
	cin>>n>>k;
	fact[0]=1; for (int i=1;i<=n*k;i++) fact[i]=1ll*fact[i-1]*i%TT;
	if (k==1) return cout<<1<<endl, 0;
	for (int i=1;i<=n;i++) F[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++) 
			F[i][j]=F[i-1][j]+1ll*(n-j+1)*F[i][j-1]%TT*C(n*k-i-(k-1)*(j-1)-1,k-2)%TT, M(F[i][j]);
	return cout<<F[n][n], 0;
}
/*
	

*/