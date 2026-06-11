#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5+10 ; 
int n,l,t,x[N],w[N],y[N] ; long long c ; 
int main(){
//	freopen("in.txt","r",stdin) ; 
	cin >> n >> l >> t ;
	for(int i = 1 ; i <= n ; i++) scanf("%d%d",&x[i],&w[i]) ;
	for(int i = 1 ; i <= n ; i++){
		int r ;
		if(w[i] == 2) w[i] = -1 ;
		r = x[i]+w[i]*t ;
		if(r > 0) (c += r/l)%=n ;
		else if(r < 0) (c += (r+1)/l-1)%=n ;
		y[i] = (r%l+l)%l ; 
	}
	sort(y+1,y+n+1) ; 
	c = (c%n+n)%n ;
	for(int i = c+1 ; i <= n ; i++) printf("%d\n",y[i]) ;
	for(int i = 1 ; i <= c ; i++) printf("%d\n",y[i]) ; 
	return 0; 
}
