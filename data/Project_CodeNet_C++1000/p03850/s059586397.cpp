#include <iostream>
#include <cstdio>
#define N 100005

using namespace std;

int n;
int val[N], func[N], nex[N];
long long sum[N];

inline void read(int &x) {
	x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}

int main() {
	read(n);
	read(val[1]), func[1] = 1;
	for(int i = 2; i <= n; ++i) {
		func[i] = (getchar() == '+' ? 1 : -1);
		read(val[i]);
//		printf("%d\n", func[i] * val[i]);
	}
	
	nex[n] = n + 1;
	for(int i = n; i > 1; --i) {
		sum[i] = val[i] + sum[i + 1];
		nex[i - 1] = (func[i] == -1 ? i : nex[i]);
	}
	
	long long ans, cur, res;
	ans = -1e18, cur = val[1];
	for(int i = 2; i <= n; ++i) {
		if(func[i] == -1) {
			res = cur - (sum[i] - sum[nex[i]]) + sum[nex[i]];
			if(res > ans) ans = res;
		}
		cur += func[i] * val[i];
	}
	
	if(cur > ans) ans = cur;
	cout << ans << endl;
	return 0;
}