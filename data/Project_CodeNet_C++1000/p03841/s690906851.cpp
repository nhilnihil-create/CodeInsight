#include<bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
const int MAXN = 510;
typedef pair<int, int> pii;

template<typename T> inline T read() {
	T x(0), f(1);
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch=='-') f=-1;
	for(; isdigit(ch); ch = getchar()) x = (x*10)+(ch^48);
	return x * f;
}

pii f[MAXN];
int ans[MAXN*MAXN], n;

int main() {
	int i, j;

	n = read<int>();
	for(i = 1; i <= n; i++) {
		f[i].fst = read<int>();
		f[i].snd = i;
	}

	sort(f+1, f+n+1);

	int l = 1;
	for(i = 1; i <= n; i++) {
		int loc = f[i].fst, id = f[i].snd;
		for(j = 1; j < id; j++) {
			ans[l] = id;
			while(ans[l]) l++;
		}
		if(l > loc) break;
		ans[loc] = id;
		while(ans[l]) l++;
	}
	if(i <= n) {
		printf("No\n");
		return 0;
	}
	l = n*n;
	while(ans[l]) l--;
	for(i = n; i >= 1; i--) {
		int loc = f[i].fst, id = f[i].snd;
		for(j = 1; j <= n-id; j++) {
			if(l < loc) break;
			ans[l] = id;
			while(ans[l]) l--;
		}
		if(j <= n-id) break;
	}
	if(i >= 1) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(i = 1; i <= n*n; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
