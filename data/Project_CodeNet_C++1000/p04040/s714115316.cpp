#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;

long long int h, w, a, b, cvp, faktoriyel[1000000];
//a=h, b=w

long long int fe(long long int base, long long int ust){
	if(ust==1)return base;
	if(ust%2==0)return (fe((base*base)%MOD, ust/2))%MOD;
	return (fe((base*base)%MOD, ust/2)*base)%MOD;
}

long long int hesapla(long long int x, long long int y){
	return  (((faktoriyel[h+w-x-y]*((fe(faktoriyel[h-x], MOD-2)*fe(faktoriyel[w-y], MOD-2))%MOD) )%MOD)
		*
			(((faktoriyel[x+y-1-1]*((fe(faktoriyel[x-1], MOD-2)*fe(faktoriyel[y-1], MOD-2))%MOD) )%MOD)
				))
	%MOD;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	faktoriyel[0]=1;
	for(int i=1;i<1000000;i++)faktoriyel[i]=(i*faktoriyel[i-1])%MOD;
	cin>>h>>w>>a>>b;
	a=h-a;
	b++;
	while(b<=w&&a>0){
		cvp=(cvp+hesapla(a, b))%MOD;
		a--;b++;
	}
	cout<<cvp;
	return 0;
}