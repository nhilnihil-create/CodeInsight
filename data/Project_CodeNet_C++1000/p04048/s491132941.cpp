#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

template<typename T> inline void getint(T &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

ll N, X, ans = 0;

inline ll calc(const ll &a, const ll &b){
	return !b ? -a : calc(b, a % b) + (a / b * b << 1);
}

int main(){
	getint(N), getint(X);
	return printf("%lld\n", calc(X, N - X) + N), 0;
}