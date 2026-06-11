#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define st first
#define nd second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
template <class T> T read(T &a) {
    a=0;char x=getchar();bool f=0;
    for(;x<'0'||x>'9';x=getchar())f|=x=='-';
	for(;x>='0'&&x<='9';x=getchar())a=(a<<3)+(a<<1)+x-'0';
    if(f)a=-a;
    return a;
}
using namespace std;

const int N = 1e5 + 5;

int d[N];

vector<int> ans;

int main() {
	int n, m;
	read(n), read(m);
	int cnt = 0;
	for (int i = 1; i <= m; ++i) {
		read(d[i]);
	}
	for (int i = 1; i <= m; ++i) {
		cnt += (d[i] & 1);
	}
	if (cnt > 2) return puts("Impossible"), 0;
	cnt = 0;
	for (int i = 1; i <= m; ++i) {
		if ((d[i] & 1) && cnt == 0) {
			swap(d[i], d[1]);
			cnt = 1;
		} else 
		if ((d[i] & 1) && cnt == 1) {
			swap(d[i], d[m]);
			break;
		}
	}
	for (int i = 1; i <= m; ++i) {
		printf("%d ", d[i]);
	}
	puts("");
	for (int i = 1; i <= m; ++i) {
		if (d[i] & 1) {
			int range = d[i] >> 1;
			for (int j = 1; j <= range; ++j) {
				ans.pb(2);
			}
			if (i == 1) {
				if (m == 1) {
					ans.pb(1);
				} else ans.pb(2);
			}
		} else {
			if (m == 1) {
				ans.pb(2);
				if (d[i] > 2) {
					ans.pb(d[i] - 2);
				}
			} else 
			if (i == 1) {
				ans.pb(1);
				ans.pb(d[i]);
			} else
			if (i == m) {
				ans.pb(1);
				if (d[i] > 2) {
					ans.pb(d[i] - 2);
				}
			} else {
				ans.pb(d[i]);
			}
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d ", ans[i]);
	}
    return 0;
}
