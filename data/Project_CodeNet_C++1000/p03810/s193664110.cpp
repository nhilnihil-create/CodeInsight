//2018-1-22
//miaomiao
//
#include <bits/stdc++.h>
using namespace std;
 
#define For(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define N (100000+5)

int Gcd(int a, int b){return !b? a: Gcd(b, a%b);}

int n, a[N];
 
int Check(){
	int odd = 0, even = 0;
	For(i, 1, n) if(a[i] & 1) ++odd; else ++even;
	
	if(even & 1) return 1;
	if(odd >= 2) return 0;
	For(i, 1, n) if(a[i] == 1) return 0;
	
	For(i, 1, n) if(a[i] & 1) --a[i];
	
	int g = a[1];
	For(i, 2, n) g = Gcd(g, a[i]);
	For(i, 1, n) a[i] /= g;

	return -1;
}
 
int main(){
	scanf("%d", &n);
	For(i, 1, n) scanf("%d", &a[i]);
	
	if(n == 1){
		if(a[1] & 1) puts("Second"); else puts("First");
		return 0;
	}
 
	int o = 0;
	while(true){
		int now = Check();
 
		if(now != -1){
			if(now ^ o) printf("First"); else puts("Second");
			break;
		}
		o ^= 1;
	}
 
	return 0;
}