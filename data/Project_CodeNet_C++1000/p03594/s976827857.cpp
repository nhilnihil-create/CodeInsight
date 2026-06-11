/* Stay hungry, stay foolish. */
/* Copyright by HenryLi */
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<sstream>
#include<stack>
#include<ctime>
#include<cmath>
#include<cctype>
#include<climits>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<bitset>
#include<complex>
using namespace std;
template <class _T> inline void read(_T &_x) {
	int _t; bool _flag=false;
	while((_t=getchar())!='-'&&(_t<'0'||_t>'9')) ;
	if(_t=='-') _flag=true,_t=getchar(); _x=_t-'0';
	while((_t=getchar())>='0'&&_t<='9') _x=_x*10+_t-'0';
	if(_flag) _x=-_x;
}
typedef long long LL;
int n, m, d;
int main() {
	//freopen("fuck.in","r",stdin);
	//freopen("fuck.out","w",stdout);
	read(n), read(m), read(d);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x = (m + i + j) / d % 2, y = (m + i - j) / d % 2;
			printf("%c", "RGBY"[2 * x + y]);
		}
		puts("");
	}
	return 0;
}
