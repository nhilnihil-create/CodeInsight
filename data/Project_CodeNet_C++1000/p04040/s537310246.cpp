#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 2e5 + 10;

int n , m , a , b , inv[N] , fac[N] , ans;

int Add(int a , int b){
	return a + b > mod ? a + b - mod : a + b;
}

int Mul(int a , int b){
	return 1ll * a * b % mod;
}

int C(int n , int m){
	int p = n + m - 2 , q = n - 1;
	return Mul(fac[p] , Mul(inv[q] , inv[p - q]));
}

int Pow(int a , int k){
	if(k == 1) return a;
	int S = Pow(a , k >> 1);
	if(k & 1) return Mul(a , Mul(S , S));
	else return Mul(S , S);
}

int main(){
	scanf("%d %d %d %d" , &n , &m , &a , &b);
	fac[0] = 1;
	for(int i = 1; i < N; i++) fac[i] = Mul(fac[i - 1] , i);
	inv[N - 1] = Pow(fac[N - 1] , mod - 2);
	for(int i = N - 2; i >= 0; i--)
		inv[i] = Mul(inv[i + 1] , i + 1);
	for(int i = 1; i <= m - b; i++)
		ans = Add(ans , Mul(C(b + i , n - a) , C(m - b - i + 1 , a)));
	printf("%d" , ans);
	return 0;
}