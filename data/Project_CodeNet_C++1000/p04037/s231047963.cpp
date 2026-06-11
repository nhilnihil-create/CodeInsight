//#include <iostream>
#include <cstdio>
#include <ctype.h>
#include <algorithm>
using namespace std;

template<typename T>
inline void read(T &num) {
	num = 0; bool w = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') w = 0; c = getchar(); }
	while(isdigit(c)) { num = num*10+c-'0';; c = getchar(); }
	num = w ? num : -num;
}

const int N = 1e5 + 10;
int n, A[N];

signed main() {
	read(n);
	for(int i = 1; i <= n; i++) read(A[i]);
	sort(A + 1, A + 1 + n); reverse(A + 1, A + 1 + n);
	for(int i = 0; i <= n; i++) {
		if(i + 1 <= A[i+1]) continue;
		int j = 0;
		for(; A[j+i+1] == i; j++) ;
		if(((A[i]-i)&1) || (j&1)) puts("First");
		else puts("Second");
		break;
	}
	return 0;
}