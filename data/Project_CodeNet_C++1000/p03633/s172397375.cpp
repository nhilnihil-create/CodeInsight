#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


//最大公約数
ll gcd(ll x,ll y){

	x = abs(x);
	y = abs(y);

	if(x < y){
		swap(x,y);
	}
	if(y == 0){
		return x;
	}else{
		return gcd(y,x%y);
	}
}

//最小公倍数
ll lcm(ll x,ll y){

	if(x > y)swap(x,y);

	return y/gcd(x,y)*x;
}

int main(){

	int N;
	scanf("%d",&N);

	ll LCM = 1;
	ll tmp;

	for(int i = 0; i < N; i++){

		scanf("%lld",&tmp);
		LCM = lcm(LCM,tmp);
	}

	printf("%lld\n",LCM);

	return 0;
}
