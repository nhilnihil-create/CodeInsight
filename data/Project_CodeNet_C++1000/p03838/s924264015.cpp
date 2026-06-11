#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<string>
#include<math.h>
#include<stdio.h>
#pragma GCC optimize(2)
#define Swap(a,b)  a ^= b ^= a ^= b
using namespace std;
typedef long long ll;
inline ll read() {
	ll c = getchar(), Nig = 1, x = 0;
	while (!isdigit(c) && c != '-')c = getchar();
	if (c == '-')Nig = -1, c = getchar();
	while (isdigit(c))x = ((x << 1) + (x << 3)) + (c ^ '0'), c = getchar();
	return Nig * x;
}
inline void Out(ll a)
{
	if (a < 0)putchar('-'), a = -a;
	if (a >= 10)Out(a / 10);
	putchar(a % 10 + '0');
}
int main() {
	ll a, b;
	a = read(), b = read();
		if (abs(a) == abs(b)) {//测试已过
			Out(1);
			return 0;
			//特判没有return，导致特例流入下方
		}
		if (a == 0) {//对了
			if (b > 0) {//测试完了
				Out(b);
			}
			else {//测试已过
				Out(1 - b);
			}
			return 0;
		}
		if (b == 0) {//对了
			if (a > 0) {
				Out(a + 1);//过了
			}
			else {
				Out(-a);
			}
			return 0;
		}
		if ((a / abs(a)) * (b / abs(b)) > 0) {//同号
			if (a < b) {
				Out(b - a);//对了
			}
			else {
				Out(2 + a - b);
			}
		}
		if (a / abs(a) * b / abs(b) < 0) {
			if (a < 0) {
				if (abs(a) < abs(b))//对了(-1,23)
					Out(b + a + 1);
				else
					Out(1 - b - a);
			}
			if (a > 0) {
				if (abs(a) > abs(b)) {
					Out(1 + b + a);//对了
				}
				else {
					Out(1 - b - a);//对了
				}
			}
		}
	return 0;
}