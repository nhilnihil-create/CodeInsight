/* 
我的思路：直接按样例一的方法构造，若$h \times w$完全被$N \times M$包含显然无解

emm，wa了一发之后发现有反例：1 4 1 3 

我的会输出[1 1 -3 1]

好吧，题解的操作确实骚，考虑我们为什么会wa。因为总和相加为正数这个条件没有被满足

现在我们要保证每个数都满足要求的基础上增大每个子矩阵对答案的贡献

直接让每个数扩大1000倍即可

对于1 4 1 3来说，[1000 1000 -2001 1000]显然合法。

*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10, INF = 1e9 + 10;
inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
int N, M, h, w;
int ans[501][501];
main() {
	N = read(); M = read(); h = read(); w = read();
	if(N % h == 0 && M % w == 0) {puts("No"); return 0;}

	int sum = 0;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++) {
			if(i % h == 0 && j % w == 0) ans[i][j] =  - h * w * 1000 + 999;
			else ans[i][j] = 1000;			
			sum += ans[i][j];
		}
	if(sum <= 0) {puts("No"); return 0;}
	puts("Yes");
	for(int i = 1; i <= N; i++, puts(""))
		for(int j = 1; j <= M; j++)
			printf("%d ", ans[i][j]);
	return 0;
}
/*

*/
