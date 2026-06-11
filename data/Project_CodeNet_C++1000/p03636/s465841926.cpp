#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<cstdlib>
#include<cctype>
#include<ctime>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll maxn = 1e5 + 5;
const ll maxm = 1e3 + 5;
template<class T>
inline T qread(T &IEE){
	register T x = 0, f = 1;
	register char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-'){
			f = -f;
		}
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return IEE = x * f;
}
template<class T>
inline void qwrite(T a){
	if(!a){
		putchar('0');
		return ;
	}
 	if(a < 0){
		putchar('-');
		a = -a;
	}
	if(a > 9) qwrite(a / 10);
	putchar(a % 10 + 48);
	return ;
}
template<class T>
inline T ab(T a){
	return (a > 0) ? a : -a;
}
template<class T>
inline void swa(T &a, T &b){
	a ^= b ^= a ^= b;
	return ;
}
string s;
int main(){
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	cin >> s;
	cout << s[0] << (int)(s.size()) - 2 << s[(int)(s.size()) - 1] << endl;
	return 0;
}
