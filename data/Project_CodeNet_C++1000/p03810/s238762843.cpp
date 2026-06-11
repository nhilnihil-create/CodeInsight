#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch=='-') f=-1;
	for(; isdigit(ch); ch = getchar()) x = (x*10)+(ch^48);
	return x * f;
}

int n, a[MAXN];

int main() {

	int i;
	n = read();
	for(i = 1; i <= n; i++) a[i] = read();
	bool flag = true;
	while(true) {
		int c = 0;
		for(i = 1; i <= n; i++) if(~a[i]&1) c++;
		if(c & 1) {
			printf("%s\n", flag ? "First" : "Second");
			return 0;
		}
		else if(c < n-1) {
			printf("%s\n", flag ? "Second" : "First");
			return 0;
		}
		else {
			for(i = 1; i <= n; i++) 
				if(a[i] & 1) a[i]--;
			for(i = 1; i <= n; i++) if(a[i] == 0) break;
			if(i <= n) {
				printf("%s\n", flag ? "Second" : "First");
				return 0;
			}
			int g = a[1];
			for(i = 2; i <= n; i++)
				g = __gcd(g, a[i]);
			for(i = 1; i <= n; i++) a[i] /= g;
		}
		flag ^= 1;
		//printf("!\n");
	}
	return 0;
}
