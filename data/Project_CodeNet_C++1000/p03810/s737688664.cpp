#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

#define maxn 100010

int n, ceven, A[maxn];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	int sum = 0; bool has1 = 0, cur = 0;
	n = read();
	for(int i = 1; i <= n; i++) A[i] = read(), ceven += !(A[i] & 1), has1 |= (A[i] == 1), (sum += A[i] - 1) &= 1;
	
	if(has1) return puts(sum ? "First" : "Second"), 0;
	if(ceven & 1) return puts("First"), 0;
	if(n - ceven > 1) return puts("Second"), 0;
	for(; ;) {
		cur ^= 1;
		for(int i = 1; i <= n; i++) if(A[i] & 1) A[i]--;
		int g = A[1];
		for(int i = 2; i <= n; i++) g = gcd(g, A[i]);
		ceven = sum = has1 = 0;
		for(int i = 1; i <= n; i++) A[i] /= g, ceven += !(A[i] & 1), has1 |= (A[i] == 1), (sum += A[i] - 1) &= 1;
		if(has1) return puts((sum ^ cur) ? "First" : "Second"), 0;
		if(n - ceven > 1) return puts(((ceven & 1) ^ cur) ? "First" : "Second"), 0;
	}
	
	return 0;
}